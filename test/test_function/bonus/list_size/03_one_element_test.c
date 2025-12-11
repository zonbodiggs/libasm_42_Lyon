/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_one_element_test.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: endoliam <endoliam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 09:54:37 by endoliam          #+#    #+#             */
/*   Updated: 2025/12/11 12:07:49 by endoliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_libasm.h"

int	list_size_one_element_test(void)
{
	t_list	*first_list;

	first_list = NULL;
	lst_add_back(&first_list, lst_new(NULL));
	if (ft_list_size(first_list) == list_size(first_list))
		return (0);
	return (-1);
}
