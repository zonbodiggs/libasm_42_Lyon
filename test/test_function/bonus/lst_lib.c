/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_lib.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: endoliam <endoliam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 08:24:25 by endoliam          #+#    #+#             */
/*   Updated: 2025/12/17 11:06:36 by endoliam         ###   ########.fr       */
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

int	compare(void *a, void *b)
{
	return (*(int *)a - *(int *)b);
}

bool	is_list_sort(t_list *begin_list, int (*cmp)())
{
	t_list		*tmp;
	int			i;

	tmp = begin_list;
	i = 0;
	(void)cmp;
	while (tmp)
	{
		if (tmp && tmp->next && cmp(tmp->data, tmp->next->data) > 0)
		{
			printf("value a is: %d\nvalut b is: %d\nat pos: %d\n",
				*(int *)tmp->data, *(int *)tmp->next->data, i);
			return (false);
		}
		i++;
		tmp = tmp->next;
	}
	return (true);
}

void	ft_list_remove_if(t_list **begin_list, void *data_ref,
			int (*cmp)(), void (*free_fct)(void *))
{
	t_list		*tmp;

	tmp = NULL;
	if (!begin_list || !*begin_list
		|| !data_ref || !cmp || !free_fct)
		return ;
	while (*begin_list)
	{
		if ((*begin_list)->data && cmp((*begin_list)->data, data_ref) == 0)
		{
			tmp = (*begin_list)->next;
			free_fct(*begin_list);
			*begin_list = tmp;
		}
		*begin_list = (*begin_list)->next;
	}
}

bool	is_lst_has(t_list *begin_list, void *data_ref, int (*cmp)())
{
	t_list		*tmp;

	tmp = begin_list;
	while (tmp)
	{
		if (cmp(tmp->data, data_ref) == 0)
			return (false);
		tmp = tmp->next;
	}
	return (true);
}
