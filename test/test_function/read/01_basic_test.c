/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_basic_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: endoliam <endoliam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 09:57:30 by endoliam          #+#    #+#             */
/*   Updated: 2025/12/10 10:27:20 by endoliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"
#include <fcntl.h>

static char	*charge_function(ssize_t(*function)(int fd, void *buff
							, size_t count), ssize_t *size)
{
	int			fd;
	static char	buff[1024];

	fd = open("test/test_function/read/test.txt", O_RDONLY);
	if (fd == -1)
		return (printf("There is no fd\n"), NULL);
	*size = (*function)(fd, buff, sizeof(buff) - 1);
	close(fd);
	buff[strlen(buff) + 1] = '\0';
	return (buff);
}

void	create_file(void)
{
	int	fd;

	fd = open("test/test_function/read/test.txt", O_TRUNC | O_CREAT | O_WRONLY,
			0644);
	if (fd == -1)
	{
		printf("Failed to load file test.txt\n");
		return ;
	}
	write(fd, "Hello World!", strlen("Hello World!"));
	close(fd);
}

int	read_basic_test(void)
{
	ssize_t	size_real;
	ssize_t	size_assembly;
	char	*buff_real;
	char	*buff_assembly;

	create_file();
	size_real = 0;
	size_assembly = 0;
	buff_real = charge_function(&read, &size_real);
	buff_assembly = charge_function(&ft_read, &size_assembly);
	remove("test/test_function/read/test.txt");
	if (buff_real && buff_assembly && strcmp(buff_real, buff_assembly) == 0
		&& size_real == size_assembly)
		return (0);
	return (-1);
}
