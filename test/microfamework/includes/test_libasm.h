/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_libasm.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: endoliam <endoliam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 09:53:45 by endoliam          #+#    #+#             */
/*   Updated: 2025/12/12 08:40:09 by endoliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_LIBASM_H
# define TEST_LIBASM_H

# include "launcher.h"
# include "libasm.h"

/*************************test mandatory*************************/
				/*********test for strlen*********/
int		strlen_launcher(void);
int		strlen_basic_test(void);
int		strlen_null_test(void);
int		strlen_bigger_string_test(void);
int		strlen_void_test(void);

				/*********test for read*********/
int		read_launcher(void);
int		read_basic_test(void);
int		read_wrond_fd_test(void);
int		read_null_buf_test(void);
int		read_bigger_string_test(void);

				/*********test for strcmp*********/
int		strcmp_launcher(void);
int		strcmp_diff_test(void);
int		strcmp_basic_test(void);
int		strcmp_null_test(void);
int		strcmp_bigger_string_test(void);
int		strcmp_void_test(void);
int		strcmp_void_s1_test(void);
int		strcmp_void_s2_test(void);
int		strcmp_bigger_s1_test(void);
int		strcmp_bigger_s2_test(void);

				/*********test for strdup*********/
int		strdup_launcher(void);
int		strdup_basic_test(void);
int		strdup_null_test(void);
int		strdup_bigger_string_test(void);
int		strdup_void_test(void);

				/*********test for strcpy*********/
int		strcpy_launcher(void);
int		strcpy_basic_test(void);
int		strcpy_null_test(void);
int		strcpy_bigger_string_test(void);
int		strcpy_void_test(void);
int		strcpy_void_s1_test(void);
int		strcpy_void_s2_test(void);
int		strcpy_bigger_s1_test(void);
int		strcpy_bigger_s2_test(void);

				/*********test for write*********/
int		write_launcher(void);
int		write_basic_test(void);
int		write_wrond_fd_test(void);
int		write_null_buf_test(void);
int		write_bigger_string_test(void);

/*************************test bonus*************************/
				/*********test for atoi_base*********/
int		atoi_base_launcher(void);

				/*********test for list_push_front*********/
int		list_push_front_launcher(void);
int		list_push_front_basic_test(void);
int		list_push_front_null_test(void);
int		list_push_front_one_element_test(void);
int		list_push_front_long_list_test(void);

				/*********test for list_size*********/
int		list_size_launcher(void);
int		list_size_basic_test(void);
int		list_size_null_test(void);
int		list_size_one_element_test(void);
int		list_size_long_list_test(void);

				/*********test for list_sort*********/
int		list_sort_launcher(void);
int		list_sort_basic_test(void);
int		list_sort_null_test(void);
int		list_sort_one_element_test(void);
int		list_sort_long_list_test(void);

				/*********test for list_remove_if*********/
int		list_remove_if_launcher(void);
int		list_remove_if_basic_test(void);
int		list_remove_if_null_test(void);
int		list_remove_if_one_element_test(void);
int		list_remove_if_long_list_test(void);

#endif