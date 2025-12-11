/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04_long_list_test.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: endoliam <endoliam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 15:01:40 by endoliam          #+#    #+#             */
/*   Updated: 2025/12/11 17:33:22 by endoliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_libasm.h"

static void	init_list(t_list **list, int size)
{
	int		i;
	int		*value;

	i = 0;
	while (i < size)
	{
		value = malloc(1 * sizeof(int));
		*value = i + 1;
		ft_list_push_front(list, value);
		i++;
	}
	return ;
}

static bool	verify_list(t_list *begin_list)
{
	int			i;
	t_list		*tmp;
	int			*value;

	tmp = begin_list;
	i = list_size(tmp);
	while (begin_list)
	{
		value = (int *)begin_list->data;
		if (*value != i)
			return (false);
		begin_list = begin_list->next;
		i--;
	}
	return (true);
}

int	list_push_front_long_list_test(void)
{
	t_list	*list;

	list = NULL;
	init_list(&list, 65535);
	if (list_size(list) == 65535 && verify_list(list))
		return (free_list(&list), 0);
	return (free_list(&list), -1);
}
