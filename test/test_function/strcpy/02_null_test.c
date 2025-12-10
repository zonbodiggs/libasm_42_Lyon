#include "libasm.h"

int strcpy_null_test(void) {
	char to_copy[1024];
	const char *src = NULL;
	char *cc = ft_strcpy(to_copy, src);
	if (cc)
		return (0);
	return (-1);
}