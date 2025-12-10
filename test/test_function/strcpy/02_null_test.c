/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_null_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: endoliam <endoliam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 10:10:56 by endoliam          #+#    #+#             */
/*   Updated: 2025/12/10 10:12:05 by endoliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

int	strcpy_null_test(void)
{
	char		to_copy[1024];
	const char	*src;
	char		*cc;

	src = NULL;
	cc = ft_strcpy(to_copy, src);
	return (-1);
}
