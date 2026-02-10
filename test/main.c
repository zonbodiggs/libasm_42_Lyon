/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: endoliam <endoliam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 09:29:11 by endoliam          #+#    #+#             */
/*   Updated: 2025/12/19 14:27:40 by endoliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_libasm.h"

int	launch_mandatory_test(char *static_library, char **env)
{
	// if (strcmp(static_library, "libasm.a"))
	// 	return (1);
	// charge_library(static_library, env);
	(void)static_library;
	(void)env;
	printf("%s", YELLOW);
	printf("****                  MANDATORY                  ****\n");
	printf("*****************************************************\n");
	printf("%s", RESET);
	strlen_launcher();
	strcpy_launcher();
	strcmp_launcher();
	write_launcher();
	read_launcher();
	strdup_launcher();
	return (0);
}

int	launch_bonus_test(char *static_library, char **env)
{
	// if (strcmp(static_library, "libasm_bonus.a"))
	// 	return (1);
	// charge_library(static_library, env);
	(void)static_library;
	(void)env;
	printf("%s", YELLOW);
	printf("****                    BONUS                    ****\n");
	printf("*****************************************************\n");
	printf("%s", RESET);
	list_push_front_launcher();
	list_size_launcher();
	list_sort_launcher();
	list_remove_if_launcher();
	atoi_base_launcher();
	return (0);
}

int	main(int ac, char **av, char **env)
{
	if (ac < 3 || ac > 4)
	{
		write(2, "error: needed only 1 arguments\n", 24);
		return (1);
	}
	printf("%s", YELLOW);
	printf("*****************************************************\n");
	printf("****               42 libasm-tests               ****\n");
	printf("%s", RESET);
	if (!strcmp(av[1], "mandatory"))
		launch_mandatory_test(av[2], env);
	else if (!strcmp(av[1], "bonus"))
		launch_bonus_test(av[2], env);
	else if (!strcmp(av[1], "all"))
	{
		launch_mandatory_test(av[2], env);
		printf("%s", YELLOW);
		printf("*****************************************************\n");
		printf("%s", RESET);
		launch_bonus_test(av[3], env);
	}
	return (0);
}
