/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_lib.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: endoliam <endoliam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 08:24:25 by endoliam          #+#    #+#             */
/*   Updated: 2025/12/16 15:37:52 by endoliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lst_tools.h"

void	list_sort(t_list **begin_list, int (*cmp)())
{
	t_list	*cmp_list;
	void	*swap_data;

	if (!begin_list || !*begin_list || !(*begin_list)->next)
		return ;
	cmp_list = *begin_list;
	swap_data = NULL;
	while (*begin_list)
	{
		cmp_list = cmp_list->next;
		if (cmp_list == NULL)
		{
			(*begin_list) = (*begin_list)->next;
			cmp_list = (*begin_list);
		}
		else if (cmp((*begin_list)->data, cmp_list->data) > 0)
		{
			swap_data = (*begin_list)->data;
			(*begin_list)->data = cmp_list->data;
			cmp_list->data = swap_data;
		}
	}
}

bool	is_list_sort(t_list *begin_list)
{
	t_list	*tmp;
	
	tmp = begin_list;
	while(tmp)
	{
		if (tmp && tmp->next && *(int *)tmp->data > *(int *)tmp->next->data)
			return (false);
	tmp = tmp->next;
	}
	return (true);
}