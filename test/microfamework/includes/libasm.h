/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libasm.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: endoliam <endoliam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 09:53:05 by endoliam          #+#    #+#             */
/*   Updated: 2025/12/10 11:53:46 by endoliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBASM_H
# define LIBASM_H

# include <aio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h> // TO DO delete this include

extern ssize_t		ft_read(int fd, void *buf, size_t count);
extern int			ft_strcmp(const char *s1, const char *s2);
extern char			*ft_strcpy(char *dest, const char *src);
extern char			*ft_strdup(const char *s);
extern size_t		ft_strlen(const char *s);
extern ssize_t		ft_write(int fd, const void *buf, size_t count);

#endif