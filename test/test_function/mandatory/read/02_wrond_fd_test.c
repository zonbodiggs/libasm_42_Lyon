/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_wrond_fd_test.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: endoliam <endoliam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 10:01:11 by endoliam          #+#    #+#             */
/*   Updated: 2025/12/10 12:23:45 by endoliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"
#include <errno.h>

static char	*charge_function(ssize_t(*function)(int fd, void *buff
							, size_t count), ssize_t *size)
{
	int			fd;
	static char	buff[1024];

	fd = -1;
	*size = (*function)(fd, buff, sizeof(buff) - 1);
	buff[strlen(buff) + 1] = '\0';
	if (errno != EBADF)
		return (NULL);
	return (buff);
}

int	read_wrond_fd_test(void)
{
	ssize_t		size_real;
	ssize_t		size_assembly;
	char		*buff_real;
	char		*buff_assembly;

	size_assembly = 0;
	size_real = 0;
	buff_real = charge_function(&read, &size_real);
	buff_assembly = charge_function(&ft_read, &size_assembly);
	if (!buff_assembly || !buff_real)
		return (-1);
	if (strcmp(buff_real, buff_assembly) == 0 && size_real == size_assembly)
		return (0);
	return (-1);
}
