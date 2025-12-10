#include "libasm.h"

int strcpy_basic_test(void) {
	char to_dup[1024];
	if (strcmp(strcpy(to_dup, "Hello World!"), ft_strcpy(to_dup, "Hello World!")) == 0)
		return (0);
	return (-1);
}