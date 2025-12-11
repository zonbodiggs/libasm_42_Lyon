/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_launcher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: endoliam <endoliam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 10:16:35 by endoliam          #+#    #+#             */
/*   Updated: 2025/12/10 10:16:54 by endoliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_libasm.h"

int	strlen_launcher(void)
{
	t_test	*testlist;

	testlist = NULL;
	printf("%sSTRLEN:%s\n", BLUE, RESET);
	load_test(&testlist, "Basic test", &strlen_basic_test, false);
	load_test(&testlist, "NULL test", &strlen_null_test, true);
	load_test(&testlist, "Bigger string test",
		&strlen_bigger_string_test, false);
	load_test(&testlist, "Void string test", &strlen_void_test, false);
	return (launch_test(testlist));
}
