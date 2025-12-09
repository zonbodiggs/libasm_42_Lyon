#ifndef TEST_H
# define TEST_H

# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/wait.h>
# include <signal.h>
# include <stdbool.h>

# define RED "\e[1;31m"
# define GREEN "\e[1;32m"
# define YELLOW "\e[1;33m"
# define BLUE "\x1B[34m"
# define MAGENTA "\x1B[35m"
# define CYAN "\x1B[36m"
# define RESET "\e[0m"

# define MAX_NAME_LENGHT 32

typedef int	(t_test_func)(void);

typedef struct s_test {

	char				name[MAX_NAME_LENGHT];
	int					id;
	t_test_func			*function;
	int					status;
	int					flags;
	int					exit_code;
	bool				signal;
	struct s_test 		*next;

} t_test;

// void	puts(const char *function_name);

void	load_test(t_test **test_list, char *test_name, t_test_func *function, bool signal);
int		start_test();
int		launch_test(t_test *test_list);

#endif