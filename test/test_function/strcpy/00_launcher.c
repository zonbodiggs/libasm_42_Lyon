#include "test_libasm.h"

int	strcpy_launcher(void) {

	t_test *testlist = NULL;

	printf("%sSTRCPY:%s\n", BLUE, RESET);

	load_test(&testlist, "Basic test", &strcpy_basic_test, false);
	load_test(&testlist, "NULL test", &strcpy_null_test, true);
	load_test(&testlist, "Bigger string test", &strcpy_bigger_string_test, false);

	return (launch_test(testlist));
}