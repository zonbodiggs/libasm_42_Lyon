/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_null_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: endoliam <endoliam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 10:04:36 by endoliam          #+#    #+#             */
/*   Updated: 2025/12/12 10:42:51 by endoliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

int	strcmp_null_test(void)
{
	const char	*s1;
	const char	*s2;

	s1 = NULL;
	s2 = "a";
	if (ft_strcmp(s1, s2))
		return (0);
	return (-1);
}
