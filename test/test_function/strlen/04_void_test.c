#include "libasm.h"

int strlen_void_test(void) {
	char *str = "";
	if (strlen(str) == ft_strlen(str))
		return (0);
	return (-1);
}