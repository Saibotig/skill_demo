#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <stdint.h>
#include <cmocka.h>
#include <stdlib.h>
#include "../util.h"

#define NUM_OF_ELEMENTS   6U

int compare (const void * a, const void * b) {
    int arg1 = *(const int*)a;
    int arg2 = *(const int*)b;
 
    if (arg1 < arg2) return -1;
    if (arg1 > arg2) return 1;
    return 0;

    // return (arg1 > arg2) - (arg1 < arg2); // possible shortcut
    // return arg1 - arg2; // erroneous shortcut (fails if INT_MIN is present)
}

static void test_compare(void **state) {
	(void) state; /* unused */

	int returnValue = 0;
	int a = 5;
	int b = 4;
	returnValue = compare((void*) &a, (void*) &b);
	assert_int_equal(returnValue, 1);

	a = 1;
	returnValue = compare((void*) &a, (void*) &b);
	assert_int_equal(returnValue, -1);

	b = 1;
	returnValue = compare((void*) &a, (void*) &b);
	assert_int_equal(returnValue, 0);
}

static void test_qsort(void **state) {
	(void) state; /* unused */

	unsigned int values[] = { 15U, 65U, 4U, 3U, 78U, 9U};
	unsigned int values_sorted[] = { 3U, 4U, 9U, 15U, 65U, 78U};

	qsort(values, NUM_OF_ELEMENTS, sizeof(unsigned int), compare);

	assert_memory_equal(&values, &values_sorted, sizeof(unsigned int) * NUM_OF_ELEMENTS);
}

static void test_addsFive(void **state) {
	(void) state; /* unused */
	int five = 0;
	addsFive(&five);
	assert_int_equal(five, 5);
}

int test_black_box(void) {
	const struct CMUnitTest tests[] = {
		cmocka_unit_test(test_qsort),
	};

	return cmocka_run_group_tests_name("black box tests of build in functions", tests, NULL, NULL);
}

int test_white_box(void) {
	const struct CMUnitTest tests[] = {
		cmocka_unit_test(test_compare),
		cmocka_unit_test(test_addsFive),
	};

	return cmocka_run_group_tests_name("white box tests of build in functions", tests, NULL, NULL);
}

int main(int arg, char* argv[]) {
	int returnCode = 0;

	returnCode |= test_black_box();
	returnCode |= test_white_box();

	return returnCode;
}