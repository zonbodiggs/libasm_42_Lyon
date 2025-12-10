/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_basic_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: endoliam <endoliam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 10:09:41 by endoliam          #+#    #+#             */
/*   Updated: 2025/12/10 10:10:49 by endoliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

int	strcpy_basic_test(void)
{
	char	to_dup[1024];

	if (strcmp(strcpy(to_dup, "Hello World!"),
			ft_strcpy(to_dup, "Hello World!")) == 0)
		return (0);
	return (-1);
}
