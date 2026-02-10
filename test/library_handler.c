/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   library_handler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: endoliam <endoliam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 14:17:26 by endoliam          #+#    #+#             */
/*   Updated: 2025/12/19 14:28:51 by endoliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "library_handler.h"
#include <stdio.h>

void	child(t_exec *cmd, int oldfd[2], int newfd[2])
{

	if (oldfd[0] == -1 && oldfd[1] == -1)
		dup2(newfd[1], STDOUT_FILENO);
	else if (is_last_cmd(cmd))
		dup2(oldfd[0], STDIN_FILENO);
	else
	{
		dup2(oldfd[0], STDIN_FILENO);
		dup2(newfd[1], STDOUT_FILENO);
	}
	close_all(newfd, NULL);
	if (oldfd[0] != -1)
		close(oldfd[0]);
	execve(cmd->cmd, cmd->args, cmd->env);
}

void	update_pipeline(int *oldfd, int *newfd)
{
	if (oldfd[0] >= 0)
		close(oldfd[0]);
	oldfd[0] = newfd[0];
	oldfd[1] = newfd[1];
	close(newfd[1]);
}

int	pipex(t_exec **cmds)
{
	pid_t	pid;
	int		status;
	int		oldfd[2];
	int		newfd[2];

	status = 0;
	memset(oldfd, -1, 2 * sizeof(int));
	memset(newfd, -1, 2 * sizeof(int));
	pipe(newfd);
	while (cmds)
	{
		pid = fork();
		if (pid == -1)
			return (-1); //free and exit
		if (pid == 0)
			child(cmds, oldfd, newfd);
		update_pipeline(oldfd, newfd);
		pipe(newfd);
	}
}

/******************extract object file from static library******************/
FILE	*extract_object_files(char *static_library, char **env)
{
	// FILE	*obj;					// extract obj files
	// char	*cmd;

	// cmd = malloc((10 + strlen(static_library)) * sizeof(char));
	// cmd[0] = '\0';
	// cmd = strcat(cmd, "ar t ");
	// cmd = strcat(cmd, static_library);
	// // printf("command is: '%s\n'", cmd);
	// obj = popen(cmd, "r");
	// free(cmd);

}

/***transform .a (static library) to .so (shared library in linux system)****/
int	transform_static_library(char *static_library, char **env)
{
	extract_object_files(static_library, env);
	// ar t libasm.a ==> recupere la liste des .o files
	// mkdir .library ==> creer un dossier library pour y mettre les (pas sur que je vais faire cela)
	// ar x libasm.a  ==> reconstruit les .o et les mettre dans le dossier .library
	// gcc -shared -o libasm.so [liste des .o] ==> extrait les 
	return (0);
}

int	charge_library(char *static_library, char **env)
{
	transform_static_library(static_library, env);
	// transform .a (static library) to .so (shared library in linux system)
	// charge dynamique library with dlopen() function be carefull of error handling and use dlerror()  void *dlopen(const char *filename, int flag); 
	// charge library descriptor send by dlopen and find his adress with dlsym() function be carefull of error handling and use dlerror()  void *dlsym(void *handle, const char *symbol);
	// close library charged with dlopen int dlclose(void *handle); 
	return (0);
}