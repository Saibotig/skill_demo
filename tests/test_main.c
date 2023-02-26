#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <stdint.h>
#include <cmocka.h>
#include <stdlib.h>

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

static void test_qsort(void **state) {
	(void) state; /* unused */

	unsigned int values[] = { 15U, 65U, 4U, 3U, 78U, 9U};
	unsigned int values_sorted[] = { 3U, 4U, 9U, 15U, 65U, 78U};

	qsort(values, NUM_OF_ELEMENTS, sizeof(unsigned int), compare);

	assert_memory_equal(&values, &values_sorted, sizeof(unsigned int) * NUM_OF_ELEMENTS);
}

int test_black_box(void) {
	const struct CMUnitTest tests[] = {
		cmocka_unit_test(test_qsort),
	};

	return cmocka_run_group_tests_name("black box tests of build in functions", tests, NULL, NULL);
}

int main(int arg, char* argv[]) {
	int returnCode = 0;

	returnCode |= test_black_box();

	return returnCode;
}