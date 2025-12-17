/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: endoliam <endoliam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 10:13:15 by endoliam          #+#    #+#             */
/*   Updated: 2025/12/17 12:34:41 by endoliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lst_tools.h"

void	lst_add_back(t_list **testlist, t_list *new)
{
	t_list	*last;

	last = *testlist;
	if (!new || !testlist)
		return ;
	if (!*testlist)
		*testlist = new;
	else
	{
		while (last->next)
			last = last->next;
		last->next = new;
	}
	return ;
}

t_list	*lst_new(void *data)
{
	t_list	*new;

	new = calloc(1, sizeof(t_list));
	if (!new)
		return (printf("error: Loading new list failed\n"), NULL);
	new->data = data;
	new->next = NULL;
	return (new);
}

int	list_size(t_list *begin_list)
{
	int	len;

	len = 0;
	while (begin_list)
	{
		begin_list = begin_list->next;
		len++;
	}
	return (len);
}

void	free_list(t_list **list)
{
	t_list	*tmp;

	while (*list)
	{
		tmp = (*list)->next;
		if ((*list)->data)
			free((*list)->data);
		free(*list);
		*list = tmp;
	}
	list = NULL;
}

void	print_list(t_list **list)
{
	t_list	*tmp;

	tmp = *list;
	while (tmp)
	{
		if (tmp->data)
			printf("value is: %d\n", *(int *)tmp->data);
		tmp = tmp->next;
	}
}
