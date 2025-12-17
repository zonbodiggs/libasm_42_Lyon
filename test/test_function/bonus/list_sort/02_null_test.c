/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_null_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: endoliam <endoliam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 12:47:45 by endoliam          #+#    #+#             */
/*   Updated: 2025/12/16 16:49:28 by endoliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

int	list_sort_null_test(void)
{
	t_list		*lst;

	lst = NULL;
	ft_list_sort(&lst, NULL);
	ft_list_sort(&lst, &ft_strcmp);
	return (0);
}
