#ifndef TOOLS_H
# define TOOLS_H

# include "launcher.h"

void		lstadd_back(t_test **testlist, t_test *new);
size_t		lst_size(t_test *testlist);
void 		free_list(t_test **testlist);

#endif