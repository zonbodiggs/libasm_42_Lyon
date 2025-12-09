#include "libasm.h"

int strcmp_basic_test(void) {
	if (strcmp("123456789", "123456789") == ft_strcmp("123456789", "123456789"))
		return 0;
	printf("strcmp is: %d, your ft_strcmp is: %d\n", strcmp("123456789", "12345678910"), ft_strcmp("123456789", "12345678910"));
	return (-1);
}
