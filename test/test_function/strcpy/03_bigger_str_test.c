/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_bigger_str_test.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: endoliam <endoliam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 10:12:16 by endoliam          #+#    #+#             */
/*   Updated: 2025/12/10 10:28:49 by endoliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

static char	*get_big_str(void)
{
	char		*res;
	long long	i;

	res = malloc(2147483648 * sizeof(char));
	i = 0;
	while (i < 2147483647)
	{
		res[i] = 'a';
		i++;
	}
	res[i++] = '\0';
	return (res);
}

static int	free_and_return(char *value1, char *value2, int return_code)
{
	free(value1);
	free(value2);
	return (return_code);
}

int	strcpy_bigger_string_test(void)
{
	char	*to_dup;
	char	*bigstr;

	to_dup = malloc(2147483648 * sizeof(char));
	bigstr = get_big_str();
	ft_strcpy(to_dup, bigstr);
	if (strcmp(to_dup, bigstr) == 0)
		return (free_and_return(to_dup, bigstr, 0));
	return (free_and_return(to_dup, bigstr, -1));
}
