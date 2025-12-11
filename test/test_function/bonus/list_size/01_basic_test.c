/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_basic_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: endoliam <endoliam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 09:54:06 by endoliam          #+#    #+#             */
/*   Updated: 2025/12/11 12:05:55 by endoliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_libasm.h"

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

int	list_size_basic_test(void)
{
	t_list	*first_list;
	t_list	*second_list;

	first_list = NULL;
	second_list = NULL;
	init_list(&first_list, 5);
	init_list(&second_list, 25);
	if (ft_list_size(first_list) == list_size(first_list)
		&& ft_list_size(second_list) == list_size(second_list))
		return (free_list(&first_list), free_list(&second_list), 0);
	return (free_list(&first_list), -1);
}
