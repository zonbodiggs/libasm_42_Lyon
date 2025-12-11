/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_null_buff.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: endoliam <endoliam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 12:10:34 by endoliam          #+#    #+#             */
/*   Updated: 2025/12/11 11:08:11 by endoliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"
#include <fcntl.h>
#include <errno.h>

static char	*charge_function(
	ssize_t(*function)(int fd, const void *buff, size_t count), ssize_t *size)
{
	int			fd;
	const char	*str;

	fd = open("test/test_function/mandatory/write/test.txt",
			O_TRUNC | O_CREAT | O_WRONLY, 0644);
	str = NULL;
	if (fd == -1)
		return (printf("Failed while creating file\n"), NULL);
	*size = (*function)(fd, str, strlen("Hello World!"));
	close(fd);
	if (errno != EFAULT)
		return (NULL);
	return ("ok");
}

int	write_null_buf_test(void)
{
	ssize_t		size_real;
	ssize_t		size_assembly;
	char		*buff_real;
	char		*buff_assembly;

	size_assembly = 0;
	size_real = 0;
	buff_real = charge_function(&write, &size_real);
	buff_assembly = charge_function(&ft_write, &size_assembly);
	remove("test/test_function/mandatory/write/test.txt");
	if (!buff_assembly || !buff_real)
		return (-1);
	if (strcmp(buff_real, buff_assembly) == 0 && size_real == size_assembly)
		return (0);
	return (-1);
	return (-1);
}
