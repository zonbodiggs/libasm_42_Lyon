/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: endoliam <endoliam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 09:29:11 by endoliam          #+#    #+#             */
/*   Updated: 2025/12/16 15:49:05 by endoliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_libasm.h"
#include "libasm.h"
#include <time.h>

int	launch_mandatory_test(void)
{
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

// static int	cmp(void *a , void *b)
// {
// 	// if (!a || !b)
// 	// 	return (0);
// 	// printf("value of data a is: %d\n", *(int *)a);
// 	// printf("value of data b is: %d\n\n", *(int *)b);
// 	return (*(int *)a - *(int *)b);
// }

// static void launch() {
// 	t_list		*list = NULL;
// 	init_list(&list, 15);
// 	t_list		*tmp = list;
// 	t_list		*to_free = list;
// 	ft_list_sort(&list, &ft_strcmp);
// 	while(tmp) {
// 		printf("value of data is: %d\n", *(int *)tmp->data);
// 		tmp = tmp->next;
// 	}
// 	free_list(&to_free);
// 	printf("\n\n\n\n\n------------------\n\n\n\n\n");
// }

void	launch_bonus_test(void)
{
	printf("%s", YELLOW);
	printf("****                    BONUS                    ****\n");
	printf("*****************************************************\n");
	printf("%s", RESET);
	// list_push_front_launcher();
	// list_size_launcher();
	list_sort_launcher();

	/*********************test to delete*********************/
	// launch();
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
		printf("*****************************************************\n");
		printf("%s", RESET);
		launch_bonus_test();
	}
	return (0);
}
