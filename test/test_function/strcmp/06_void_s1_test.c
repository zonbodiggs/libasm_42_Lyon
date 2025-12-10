/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   06_void_s1_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: endoliam <endoliam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 10:31:19 by endoliam          #+#    #+#             */
/*   Updated: 2025/12/10 10:50:43 by endoliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

int	strcmp_void_s1_test(void)
{
	if (strcmp("s1", "") == ft_strcmp("s1", ""))
		return (0);
	printf("strcmp is: %d, ft_strcmp is: %d\n", strcmp("s1", ""), ft_strcmp("s1", ""));
	return (-1);
}
