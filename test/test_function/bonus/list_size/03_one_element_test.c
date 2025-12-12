/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_one_element_test.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: endoliam <endoliam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 09:54:37 by endoliam          #+#    #+#             */
/*   Updated: 2025/12/12 08:41:56 by endoliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

int	list_size_one_element_test(void)
{
	t_list	*list;

	list = NULL;
	lst_add_back(&list, lst_new(NULL));
	if (ft_list_size(list) == list_size(list))
		return (free_list(&list), 0);
	return (free_list(&list), -1);
}
