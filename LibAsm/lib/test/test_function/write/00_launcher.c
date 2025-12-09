#include "test_libasm.h"

int	write_launcher(void) {

	t_test *testlist = NULL;

	printf("%sWRITE:%s\n", BLUE, RESET);

	load_test(&testlist, "Basic test", &write_basic_test, false);
	load_test(&testlist, "Wrong fd test", &write_null_test, false);
	load_test(&testlist, "Bigger string test", &write_bigger_string_test, false);

	return (launch_test(testlist));
}