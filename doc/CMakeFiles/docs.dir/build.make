# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.26

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = C:\Repos\CMAKE\bin\cmake.exe

# The command to remove a file.
RM = C:\Repos\CMAKE\bin\cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Repos\Cmocka_Test\cmocka

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Repos\Cmocka_Test\cmocka\build

# Utility rule file for docs.

# Include any custom commands dependencies for this target.
include doc/CMakeFiles/docs.dir/compiler_depend.make

# Include the progress variables for this target.
include doc/CMakeFiles/docs.dir/progress.make

doc/CMakeFiles/docs: doc/Doxyfile.docs
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=C:\Repos\Cmocka_Test\cmocka\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Generate API documentation for docs"
	cd /d C:\Repos\Cmocka_Test\cmocka\doc && C:\Repos\CMAKE\bin\cmake.exe -E make_directory C:/Repos/Cmocka_Test/cmocka/build/doc
	cd /d C:\Repos\Cmocka_Test\cmocka\doc && "C:\Program Files\doxygen\bin\doxygen.exe" C:/Repos/Cmocka_Test/cmocka/build/doc/Doxyfile.docs

docs: doc/CMakeFiles/docs
docs: doc/CMakeFiles/docs.dir/build.make
.PHONY : docs

# Rule to build all files generated by this target.
doc/CMakeFiles/docs.dir/build: docs
.PHONY : doc/CMakeFiles/docs.dir/build

doc/CMakeFiles/docs.dir/clean:
	cd /d C:\Repos\Cmocka_Test\cmocka\build\doc && $(CMAKE_COMMAND) -P CMakeFiles\docs.dir\cmake_clean.cmake
.PHONY : doc/CMakeFiles/docs.dir/clean

doc/CMakeFiles/docs.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Repos\Cmocka_Test\cmocka C:\Repos\Cmocka_Test\cmocka\doc C:\Repos\Cmocka_Test\cmocka\build C:\Repos\Cmocka_Test\cmocka\build\doc C:\Repos\Cmocka_Test\cmocka\build\doc\CMakeFiles\docs.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : doc/CMakeFiles/docs.dir/depend

