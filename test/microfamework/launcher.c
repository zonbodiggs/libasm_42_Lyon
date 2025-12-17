/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launcher.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: endoliam <endoliam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 09:32:07 by endoliam          #+#    #+#             */
/*   Updated: 2025/12/17 17:20:31 by endoliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "launcher.h"
#include "tools.h"

void	load_test(t_test **testlist, char *test_name
					, t_test_func *function, bool signal)
{
	t_test	*new;

	new = calloc(1, sizeof(t_test));
	if (!new)
		return (free_and_return(new));
	if (test_name)
	{
		strncpy(new->name, test_name, MAX_NAME_LENGHT - 1);
		new->name[MAX_NAME_LENGHT - 1] = '\0';
	}
	if (function)
		new->function = function;
	if (signal)
		new->signal = signal;
	new->next = NULL;
	lstadd_back(testlist, new);
}

static void	child_process(t_test *testlist)
{
	int	exit_code;

	exit_code = ((*testlist).function)();
	free_test_list(&testlist);
	exit(exit_code);
}

static void	print_result(t_test testlist)
{
	char	*color;

	color = GREEN;
	printf("	>%s: ", testlist.name);
	if (testlist.flags != 0)
	{
		if (!testlist.signal)
			color = RED;
		if (testlist.flags == SIGBUS)
			printf("%s[SIGBUS]%s\n", color, RESET);
		else if (testlist.flags == SIGSEGV)
			printf("%s[SIGSEGV]%s\n", color, RESET);
	}
	else if (testlist.exit_code != 0)
		printf("%s[KO]%s\n", RED, RESET);
	else if (testlist.exit_code == 0)
		printf("%s[OK]%s\n", GREEN, RESET);
	return ;
}

static void	check_result(t_test *testlist)
{
	if (WIFSIGNALED(testlist->status))
		testlist->flags = WTERMSIG(testlist->status);
	testlist->exit_code = WEXITSTATUS(testlist->status);
}

int	launch_test(t_test *testlist)
{
	t_test	*exec;

	exec = testlist;
	while (exec)
	{
		exec->id = fork();
		if (exec->id == -1)
			exit_error(testlist);
		if (exec->id == 0)
			child_process(exec);
		if (wait(&exec->status) == -1)
			exit_error(testlist);
		check_result(exec);
		print_result(*exec);
		free_one_element(&exec);
	}
	return (0);
}

// printf("\x1b[2K"); // supprime la ligne du terminal