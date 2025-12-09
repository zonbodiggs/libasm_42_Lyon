#include "test_libasm.h"

int	strdup_launcher(void) {

	t_test *testlist = NULL;

	printf("%sSTRDUP:%s\n", BLUE, RESET);

	load_test(&testlist, "Basic test", &strdup_basic_test, false);
	load_test(&testlist, "NULL test", &strdup_null_test, false);
	load_test(&testlist, "Bigger string test", &strdup_bigger_string_test, false);

	return (launch_test(testlist));
}