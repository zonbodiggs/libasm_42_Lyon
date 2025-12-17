/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   05_already_sort_test.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: endoliam <endoliam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 16:52:20 by endoliam          #+#    #+#             */
/*   Updated: 2025/12/17 10:54:32 by endoliam         ###   ########.fr       */
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
		lst_add_back(list, lst_new(value));
		i++;
	}
	return ;
}

int	list_sort_long_already_sort(void)
{
	t_list		*list;
	t_list		*tofree;

	list = NULL;
	init_list(&list, 50);
	tofree = list;
	ft_list_sort(&list, &ft_strcmp);
	if (is_list_sort(tofree, &ft_strcmp))
		return (free_list(&tofree), 0);
	return (free_list(&tofree), -1);
}
