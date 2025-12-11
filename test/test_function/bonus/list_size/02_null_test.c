/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_NULL_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: endoliam <endoliam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 11:41:42 by endoliam          #+#    #+#             */
/*   Updated: 2025/12/11 12:00:44 by endoliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_libasm.h"

int	list_size_null_test(void)
{
	t_list	*first_list;

	first_list = NULL;
	if (ft_list_size(first_list) == list_size(first_list))
		return (0);
	return (-1);
}
