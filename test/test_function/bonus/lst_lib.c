/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_lib.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: endoliam <endoliam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 08:24:25 by endoliam          #+#    #+#             */
/*   Updated: 2025/12/18 08:12:35 by endoliam         ###   ########.fr       */
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

void	list_remove_if(t_list **begin_list, void *data_ref,
			int (*cmp)(), void (*free_fct)(void *))
{
	if (!begin_list || !*begin_list
		|| !data_ref || !cmp || !free_fct)
		return ;
	while (*begin_list)
	{
		if ((*begin_list)->data && cmp((*begin_list)->data, data_ref) == 0)
		{
			free_fct((*begin_list)->data);
			(*begin_list)->data = NULL;
		}
		*begin_list = (*begin_list)->next;
	}
}

//0x7fffffffdc10 || 0xffffdc10