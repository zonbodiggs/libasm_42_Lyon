#include "test_libasm.h"

int	strcmp_launcher(void) {

	t_test *testlist = NULL;

	printf("%sSTRCMP:%s\n", BLUE, RESET);

	load_test(&testlist, "Basic test", &strcmp_basic_test, false);
	load_test(&testlist, "Diff test", &strcmp_diff_test, false);
	load_test(&testlist, "NULL test", &strcmp_null_test, true);
	load_test(&testlist, "Bigger string test", &strcmp_bigger_string_test, true);

	return (launch_test(testlist));
}