#include "libasm.h"

int strlen_null_test(void) {
	char *str = NULL;
	ft_strlen(str);
	return (-1);
}