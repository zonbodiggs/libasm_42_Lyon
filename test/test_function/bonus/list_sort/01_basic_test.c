/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_basic_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: endoliam <endoliam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 12:47:27 by endoliam          #+#    #+#             */
/*   Updated: 2025/12/17 10:56:12 by endoliam         ###   ########.fr       */
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

static t_list	*create_and_execute(int (*cmp)(), int size)
{
	t_list		*lst;
	t_list		*tmp;

	lst = NULL;
	init_list(&lst, size);
	tmp = lst;
	ft_list_sort(&tmp, cmp);
	return (lst);
}

int	list_sort_basic_test(void)
{
	t_list		*list;
	t_list		*list1;
	t_list		*list2;
	t_list		*list3;

	list = create_and_execute(&compare, 15);
	list1 = create_and_execute(&ft_strcmp, 20);
	list2 = create_and_execute(&strcmp, 25);
	list3 = create_and_execute(&compare, 25);
	if (is_list_sort(list, &compare) && is_list_sort(list1, &ft_strcmp)
		&& is_list_sort(list2, &strcmp) && is_list_sort(list3, &compare))
		return (free_list(&list), free_list(&list1)
			, free_list(&list2), free_list(&list3), 0);
	return (free_list(&list), free_list(&list1)
		, free_list(&list2), free_list(&list3), -1);
}
