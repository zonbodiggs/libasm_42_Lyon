/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   library_handler.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: endoliam <endoliam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 14:19:59 by endoliam          #+#    #+#             */
/*   Updated: 2025/12/19 14:44:03 by endoliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBRARY_HANDLER_H
# define LIBRARY_HANDLER_H

# include <fcntl.h>  

typedef struct s_exec 
{
	char			*cmd;
	char			**args;
	char			**env;
	struct s_exec	*next;
}		t_exec;

int		charge_library(char *static_library, char **env);

#endif