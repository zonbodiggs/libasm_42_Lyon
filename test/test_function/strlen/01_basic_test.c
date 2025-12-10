#include "libasm.h"

int strlen_basic_test(void) {
	if (strlen("Hello World!") == ft_strlen("Hello World!"))
		return 0;
	return -1;
}