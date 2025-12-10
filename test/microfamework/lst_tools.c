/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: endoliam <endoliam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 09:42:41 by endoliam          #+#    #+#             */
/*   Updated: 2025/12/10 09:44:37 by endoliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"

void	lstadd_back(t_test **testlist, t_test *new)
{
	t_test	*last;

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

size_t	lst_size(t_test *testlist)
{
	size_t	len;

	len = 0;
	while (testlist)
	{
		testlist = testlist->next;
		len++;
	}
	return (len);
}

void	free_list(t_test **testlist)
{
	t_test	*tmp;

	tmp = *testlist;
	while (*testlist)
	{
		tmp = tmp->next;
		free(*testlist);
		*testlist = tmp;
	}
}

void	free_one_element(t_test **testlist)
{
	t_test	*next;

	next = (*testlist)->next;
	if (*testlist)
		free(*testlist);
	*testlist = next;
}
