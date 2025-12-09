#include "libasm.h"

int strcmp_null_test(void) {
	const char *s1 = NULL;
	const char *s2 = NULL;

	if (ft_strcmp(s1, s2))
		return (0);
	return (-1);
}
