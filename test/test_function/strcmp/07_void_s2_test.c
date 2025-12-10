/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   07_void_s2_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: endoliam <endoliam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 10:31:45 by endoliam          #+#    #+#             */
/*   Updated: 2025/12/10 10:51:10 by endoliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

int	strcmp_void_s2_test(void)
{
	if (strcmp("", "s2") == ft_strcmp("", "s2"))
		return (0);
	printf("strcmp is: %d, ft_strcmp is: %d\n", strcmp("", "s2"), ft_strcmp("", "s2"));
	return (-1);
}
