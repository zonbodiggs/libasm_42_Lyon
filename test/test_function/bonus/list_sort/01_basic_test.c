/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_basic_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: endoliam <endoliam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 12:47:27 by endoliam          #+#    #+#             */
/*   Updated: 2025/12/16 15:50:38 by endoliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"
#include "time.h"

static void	init_list(t_list **list, int size)
{
	int		i;
	int		*value;

	i = 0;
	srand(time(NULL));
	while (i < size)
	{
		value = malloc(2 * sizeof(int));
		*value = rand() % 101;
		ft_list_push_front(list, value);
		i++;
	}
	return ;
}

// static int	cmp(void *a , void *b)
// {
// 	return (*(int *)a - *(int *)b);
// }

int	list_sort_basic_test(void)
{
	t_list		*list;
	t_list		*tmp;

	list = NULL;
	init_list(&list, 15);
	tmp = list;
	ft_list_sort(&list, &ft_strcmp);
	if (is_list_sort(list))
		return(free_list(&list), 0);
	while(tmp) {
		printf("value of data is: %d\n", *(int *)tmp->data);
		tmp = tmp->next;
	}
	return (free_list(&list), -1);
}
