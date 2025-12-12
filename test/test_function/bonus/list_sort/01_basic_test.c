/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_basic_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: endoliam <endoliam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 12:47:27 by endoliam          #+#    #+#             */
/*   Updated: 2025/12/12 10:46:51 by endoliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

static void	init_list(t_list **list, int size)
{
	int		i;
	int		*value;

	i = 0;
	while (i < size)
	{
		value = malloc(2 * sizeof(int));
		*value = i + 1;
		ft_list_push_front(list, value);
		i++;
	}
	return ;
}

static int	cmp(int a, int b)
{
	return a - b;
}

int	list_sort_basic_test(void)
{
	t_list		*list;

	list = NULL;
	init_list(&list, 15);
	ft_list_sort(&list, &cmp);
	while(list) {
		printf("value of data is: %d\n", *(int *)list->data);
		list = list->next;
	}
	return (-1);
}
