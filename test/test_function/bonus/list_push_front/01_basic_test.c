/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_basic_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: endoliam <endoliam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 15:00:38 by endoliam          #+#    #+#             */
/*   Updated: 2025/12/11 16:02:29 by endoliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_libasm.h"

static void	init_list(t_list **list, int size)
{
	int		i;

	i = 0;
	while (i < size)
	{
		ft_list_push_front(list, NULL);
		i++;
	}
	return ;
}

int	list_push_front_basic_test(void)
{
	t_list	*list;

	list = NULL;
	init_list(&list, 15);
	if (list_size(list) == 15)
		return (free_list(&list), 0);
	return (free_list(&list), -1);
}
