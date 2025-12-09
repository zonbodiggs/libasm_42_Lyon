#include "libasm.h"

static char	*get_big_str() {
	char *res = NULL;
	int i = 0;

	while(i < 65538) {
		res[i] = 'a';
		i++;
	}
	return (res);
}

int strlen_bigger_string_test(void) {
	const char *bigstr = get_big_str();
	ft_strlen(bigstr);
	return (-1);
}
