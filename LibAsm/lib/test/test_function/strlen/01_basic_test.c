#include "libasm.h"

int strlen_basic_test(void) {
	if (strlen("hello") == ft_strlen("hello"))
		return 0;
	return -1;
}