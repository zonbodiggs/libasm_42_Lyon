/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_basic_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: endoliam <endoliam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 15:00:38 by endoliam          #+#    #+#             */
/*   Updated: 2025/12/12 08:41:19 by endoliam         ###   ########.fr       */
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

int	list_push_front_basic_test(void)
{
	t_list	*list;

	list = NULL;
	init_list(&list, 15);
	if (list_size(list) == 15 && verify_list(list))
		return (free_list(&list), 0);
	return (free_list(&list), -1);
}
