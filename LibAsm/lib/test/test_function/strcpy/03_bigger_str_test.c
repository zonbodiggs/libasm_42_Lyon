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

int strcpy_bigger_string_test(void) {
	char to_dup[1024];
	ft_strcpy(to_dup, get_big_str());
	return (-1);
}