#include "libasm.h"

static char	*get_big_str(void) {
	char *res = malloc(2147483648 * sizeof(char));
	long long i = 0;

	while(i < 2147483647) {
		res[i] = 'a';
		i++;
	}
	res[i++] = '\0';
	return (res);
}

int strcpy_bigger_string_test(void) {
	char *to_dup =  malloc(2147483648 * sizeof(char));
	char *bigstr = get_big_str();
	ft_strcpy(to_dup, bigstr);
	if (strcmp(to_dup, bigstr) == 0) {
		free(bigstr);
		free(to_dup);
		return (0);
	}
	free(bigstr);
	free(to_dup);
	return (-1);
}