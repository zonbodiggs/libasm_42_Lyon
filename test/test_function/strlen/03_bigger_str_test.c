/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_bigger_str_test.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: endoliam <endoliam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 10:17:55 by endoliam          #+#    #+#             */
/*   Updated: 2025/12/10 10:18:57 by endoliam         ###   ########.fr       */
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

static int	free_and_return(char *value_to_free, int return_code)
{
	free(value_to_free);
	return (return_code);
}

int	strlen_bigger_string_test(void)
{
	char	*bigstr;

	bigstr = get_big_str();
	if (ft_strlen(bigstr) == strlen(bigstr))
		return (free_and_return(bigstr, 0));
	return (free_and_return(bigstr, -1));
}
