/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04_long_list_test.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: endoliam <endoliam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 09:55:19 by endoliam          #+#    #+#             */
/*   Updated: 2025/12/12 08:42:02 by endoliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

static void	init_list(t_list **list, int size)
{
	int		i;

	i = 0;
	while (i < size)
	{
		lst_add_back(list, lst_new(NULL));
		i++;
	}
	return ;
}

int	list_size_long_list_test(void)
{
	t_list	*list;

	list = NULL;
	init_list(&list, 65535);
	if (ft_list_size(list) == list_size(list))
		return (free_list(&list), 0);
	return (free_list(&list), -1);
}
