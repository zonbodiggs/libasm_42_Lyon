#include "libasm.h"

char	*get_big_str(void) {
	char *res = malloc(2147483648 * sizeof(char));
	long long i = 0;

	while(i < 2147483647) {
		res[i] = 'a';
		i++;
	}
	res[i++] = '\0';
	return (res);
}

int strlen_bigger_string_test(void) {
	char *bigstr = get_big_str();
	if (ft_strlen(bigstr) == strlen(bigstr)) {
		free(bigstr);
		return (0);
	}
	free(bigstr);
	return (-1);
}
