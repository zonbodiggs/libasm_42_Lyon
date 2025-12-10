#include "tools.h"

void	lstadd_back(t_test **testlist, t_test *new) {

	if (!new || !testlist)
		return ;
	if (!*testlist) 
		*testlist = new;
	else {
		t_test *last = *testlist;
		while (last->next)
			last = last->next;
		last->next = new;
	}

	return ;
}

size_t	lst_size(t_test *testlist) {
	size_t len = 0;

	while(testlist) {
		testlist = testlist->next;
		len++;
	}
	return (len);
}

void free_list(t_test **testlist) {
	t_test *tmp = *testlist;
	while (*testlist) {
		tmp = tmp->next;
		free(*testlist);
		*testlist = tmp;
	}
}

void free_one_element(t_test **testlist) {
	t_test *next = (*testlist)->next;
	if (*testlist) 
		free(*testlist);
	*testlist = next;
}
