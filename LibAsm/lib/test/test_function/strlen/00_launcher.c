#include "test_libasm.h"

int	strlen_launcher(void) {

	t_test *testlist = NULL;

	printf("%sSTRLEN:%s\n", BLUE, RESET);

	load_test(&testlist, "Basic test", &strlen_basic_test, false);
	load_test(&testlist, "NULL test", &strlen_null_test, true);
	load_test(&testlist, "Bigger string test", &strlen_bigger_string_test, true);

	return (launch_test(testlist));
}