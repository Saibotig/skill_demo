project(tests C)

set(TEST_EXCEPTION_HANDLER FALSE)
if (HAVE_SIGNAL_H)
    set(TEST_EXCEPTION_HANDLER TRUE)
endif()
if (WIN32)
    # FIXME: The exception handler doesn't work on Windows
    set(TEST_EXCEPTION_HANDLER FALSE)
endif()
if (CMAKE_BUILD_TYPE)
    string(TOLOWER "${CMAKE_BUILD_TYPE}" CMAKE_BUILD_TYPE_LOWER)
    if (CMAKE_BUILD_TYPE_LOWER STREQUAL "undefinedsanitizer")
        set(TEST_EXCEPTION_HANDLER FALSE)
    endif()
endif()

### ADD TESTS HERE

set(CMOCKA_TESTS
    test_main
    #test_expect_check
    )

if (TEST_EXCEPTION_HANDLER)
    list(APPEND CMOCKA_TESTS test_exception_handler)
endif()

foreach(_CMOCKA_TEST ${CMOCKA_TESTS})
    add_cmocka_test(${_CMOCKA_TEST}
                    SOURCES ${_CMOCKA_TEST}.c ../util.c
                    COMPILE_OPTIONS ${DEFAULT_C_COMPILE_FLAGS} -D_GNU_SOURCE -D_XOPEN_SOURCE=700
                    LINK_LIBRARIES cmocka::static
                    LINK_OPTIONS ${DEFAULT_LINK_FLAGS})
    target_include_directories(${_CMOCKA_TEST} PRIVATE ${cmocka_BINARY_DIR})

    add_cmocka_test_environment(${_CMOCKA_TEST})
endforeach()

foreach(_TEST_OUTPUT_FMT ${TEST_OUTPUT_FMTS})
    foreach(_OUTPUT_TEST ${OUTPUT_TESTS})
        set(TEST_NAME ${_OUTPUT_TEST}_${_TEST_OUTPUT_FMT})
        add_test(${TEST_NAME} ${TARGET_SYSTEM_EMULATOR} ${_OUTPUT_TEST})
        add_cmocka_test_environment(${TEST_NAME})

        set_property(
            TEST
            ${TEST_NAME}
            APPEND
            PROPERTY
                ENVIRONMENT CMOCKA_MESSAGE_OUTPUT=${_TEST_OUTPUT_FMT}
            )

        list(LENGTH ${TEST_NAME}_out len)
        list(GET ${TEST_NAME}_out 0 output)
        if(len GREATER 1)
            list(REMOVE_AT ${TEST_NAME}_out 0)
            foreach(line ${${TEST_NAME}_out})
                set(output "${output}[ \n\r]+${line}")
            endforeach()
        endif()

        set_tests_properties(
            ${TEST_NAME}
            PROPERTIES
            PASS_REGULAR_EXPRESSION
            ${output}
        )
    endforeach()
endforeach()
