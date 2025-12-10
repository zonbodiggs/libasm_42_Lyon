/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_launcher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: endoliam <endoliam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 09:54:42 by endoliam          #+#    #+#             */
/*   Updated: 2025/12/10 09:55:46 by endoliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_libasm.h"

int	read_launcher(void)
{
	t_test	*testlist;

	testlist = NULL;
	printf("%sREAD:%s\n", BLUE, RESET);
	load_test(&testlist, "Basic test", &read_basic_test, false);
	load_test(&testlist, "Wrong fd test", &read_wrond_fd_test, false);
	load_test(&testlist, "Bigger string test", &read_bigger_string_test, false);
	return (launch_test(testlist));
}
