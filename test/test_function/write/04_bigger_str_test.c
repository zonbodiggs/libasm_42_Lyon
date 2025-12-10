/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04_bigger_str_test.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: endoliam <endoliam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 10:25:23 by endoliam          #+#    #+#             */
/*   Updated: 2025/12/10 15:21:21 by endoliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"
#include <fcntl.h>

static char	*get_big_str(void)
{
	char			*res;
	long long		i;

	res = malloc(65535 * sizeof(char));
	i = 0;
	while (i < 65534)
	{
		res[i] = 'a';
		i++;
	}
	res[i++] = '\0';
	return (res);
}

static char	*charge_function(
	ssize_t(*function)(int fd, const void *buff, size_t count), ssize_t *size)
{
	int			fd;
	static char	*buff;

	fd = open("test/test_function/write/test.txt",
			O_TRUNC | O_CREAT | O_WRONLY, 0644);
	buff = get_big_str();
	if (fd == -1)
		return (printf("Failed while creating file\n"), NULL);
	*size = (*function)(fd, buff, 65535);
	close(fd);
	return (buff);
}

int	write_bigger_string_test(void)
{
	ssize_t		size_real;
	ssize_t		size_assembly;
	char		*buff_real;
	char		*buff_assembly;

	size_real = 0;
	size_assembly = 0;
	buff_real = charge_function(&write, &size_real);
	buff_assembly = charge_function(&ft_write, &size_assembly);
	remove("test/test_function/write/test.txt");
	if (strcmp(buff_real, buff_assembly) == 0 && size_real == size_assembly)
		return (free(buff_assembly), free(buff_real), 0);
	return (free(buff_assembly), free(buff_real), -1);
}
