/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_basic_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: endoliam <endoliam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 10:15:35 by endoliam          #+#    #+#             */
/*   Updated: 2025/12/10 15:24:04 by endoliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

int	strdup_basic_test(void)
{
	char	*dest_real;
	char	*dest_assembly;

	dest_real = strdup("Hello World!");
	dest_assembly = ft_strdup("Hello World!");
	if (!dest_assembly)
		return (free(dest_real), -1);
	if (strcmp(dest_assembly, dest_real) == 0)
		return (free(dest_assembly), free(dest_real), 0);
	return (free(dest_assembly), free(dest_real), -1);
}
