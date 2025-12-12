/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_one_element_test.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: endoliam <endoliam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 15:01:19 by endoliam          #+#    #+#             */
/*   Updated: 2025/12/12 08:41:30 by endoliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

int	list_push_front_one_element_test(void)
{
	t_list	*list;
	int		*value;
	int		*value_to_check;

	list = NULL;
	value = malloc(1 * sizeof(int));
	*value = 1;
	ft_list_push_front(&list, value);
	value_to_check = (int *)list->data;
	if (list_size(list) == 1 && *value_to_check == 1)
		return (free_list(&list), 0);
	return (free_list(&list), -1);
}
