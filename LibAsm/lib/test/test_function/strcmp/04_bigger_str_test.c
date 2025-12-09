#include "libasm.h"

static const char	*get_big_str() {
	char *res = NULL;
	long long i = 0;

	while(i < 2147483649) {
		res[i] = 'a';
		i++;
	}
	return (res);
}

int strcmp_bigger_string_test(void) {

	if (ft_strcmp("bonjour", get_big_str()))
		return (0);
	return (-1);
}