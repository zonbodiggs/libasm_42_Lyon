/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_wrond_fd_test.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: endoliam <endoliam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 10:01:11 by endoliam          #+#    #+#             */
/*   Updated: 2025/12/10 10:01:16 by endoliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

// static char *charge_function(ssize_t(*function)(int fd, void *buff, size_t count), ssize_t *size) {
// 	int fd = -1;
// 	static char buff[1024];

// 	*size = (*function)(fd, buff, sizeof(buff) - 1);
// 	buff[strlen(buff) + 1] = '\0';
// 	return (buff);
// }

int read_wrond_fd_test(void) {
	// ssize_t size_real = 0;
	// ssize_t size_assembly = 0;

	// char *buff_real = charge_function(&read, &size_real);
	// char *buff_assembly = charge_function(&ft_read, &size_assembly);
	// if (strcmp(buff_real, buff_assembly) == 0 && size_real == size_assembly)
	// 	return (0);
	// printf("buff read is: %s, buff ft_read is: %s\n", buff_real, buff_assembly);
	// printf("size read is: %zd, size ft_read is: %zd\n", size_real, size_assembly);
	return (-1);
}

