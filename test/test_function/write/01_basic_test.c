/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_basic_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: endoliam <endoliam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 10:20:21 by endoliam          #+#    #+#             */
/*   Updated: 2025/12/10 10:28:09 by endoliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"
#include <fcntl.h>

static char	*read_file(void)
{
	int			fd;
	static char	buff[1024];

	fd = open("test/test_function/write/test.txt", O_RDONLY);
	if (fd == -1)
		return (printf("There is no fd\n"), NULL);
	read(fd, buff, sizeof(buff) - 1);
	close(fd);
	buff[strlen(buff) + 1] = '\0';
	return (buff);
}

static char	*charge_function(
	ssize_t(*function)(int fd, const void *buff, size_t count), ssize_t *size)
{
	int		fd;

	fd = open("test/test_function/write/test.txt",
			O_TRUNC | O_CREAT | O_WRONLY, 0644);
	if (fd == -1)
		return (printf("Failed while creating file\n"), NULL);
	*size = (*function)(fd, "Hello World!", strlen("Hello World!"));
	close(fd);
	return (read_file());
}

int	write_basic_test(void)
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
		return (0);
	return (-1);
}
