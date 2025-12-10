/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: endoliam <endoliam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 09:29:11 by endoliam          #+#    #+#             */
/*   Updated: 2025/12/10 15:32:53 by endoliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_libasm.h"
#include "libasm.h"

int	launch_mandatory_test(void)
{
	printf("%s", YELLOW);
	printf("****                  MANDATORY                  ****\n");
	printf("*****************************************************\n");
	printf("%s", RESET);
	read_launcher();
	strcmp_launcher();
	strcpy_launcher();
	strdup_launcher();
	strlen_launcher();
	write_launcher();
	return (0);
}

void	launch_bonus_test(void)
{
	printf("%s", YELLOW);
	printf("****                    BONUS                    ****\n");
	printf("*****************************************************\n");
	printf("%s", RESET);
}

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		write(2, "error: needed only 1 arguments\n", 24);
		return (1);
	}
	printf("%s", YELLOW);
	printf("*****************************************************\n");
	printf("****               42 libasm-tests               ****\n");
	printf("%s", RESET);
	if (!strcmp(av[1], "mandatory"))
		launch_mandatory_test();
	else if (!strcmp(av[1], "bonus"))
		launch_bonus_test();
	else if (!strcmp(av[1], "all"))
	{
		launch_mandatory_test();
		printf("%s", YELLOW);
		printf("%s*****************************************************%s\n");
		printf("%s", RESET);
		launch_bonus_test();
	}
	return (0);
}
