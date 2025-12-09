#include "launcher.h"
#include "tools.h"

void load_test(t_test **testlist, char *test_name, t_test_func *function, bool signal) {
	t_test	*new = calloc(1, sizeof(t_test));

	if (!new)
		exit(1); // TODO: free and exit

	if (test_name) {
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

int start_test() {
	return (0);
}

void	child_process(t_test testlist) {
	exit (((*testlist.function)()));
}

void 	print_result(t_test testlist) {
	// printf("flags is %d\n", testlist.flags);
	printf("	>%s: ", testlist.name);
	if (testlist.flags != 0) {
		char *color = NULL;
		if (testlist.signal)
			color = GREEN;
		else
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

void check_result(t_test *testlist) {
	if (WIFSIGNALED(testlist->status)) {
		testlist->flags = WTERMSIG(testlist->status);
	}
	testlist->exit_code = WEXITSTATUS(testlist->status);
	// printf("exit status = %d\n", testlist->status);
	// printf("exit code = %d\n", testlist->exit_code);
}

void exit_error(t_test *testlist) {
	free_list(&testlist);
	exit(-1);
}

int launch_test(t_test *testlist) {

	t_test		*exec = testlist;

	while (exec) {
		// printf("test is %s\n", exec->name);
		exec->id = fork();
		if (exec->id == -1)
			exit_error(testlist);
		if (exec->id == 0) {
			child_process(*exec);
		}
		if (wait(&exec->status) == -1)
			exit_error(testlist);
		check_result(exec);
		print_result(*exec);
		exec = exec->next;
	}
	free_list(&testlist);
	return (0);
}