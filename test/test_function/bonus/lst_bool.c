/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_bool.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: endoliam <endoliam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 08:11:47 by endoliam          #+#    #+#             */
/*   Updated: 2025/12/18 08:12:28 by endoliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lst_tools.h"

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

bool	is_lst_has(t_list *begin_list, void *data_ref, int (*cmp)())
{
	t_list		*tmp;

	tmp = begin_list;
	while (tmp)
	{
		if (tmp->data && cmp(tmp->data, data_ref) == 0)
		{
			printf("ur such an asshole\n");
			return (true);
		}
		tmp = tmp->next;
	}
	return (false);
}
