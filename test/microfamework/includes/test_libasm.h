#ifndef TEST_LIBASM_H
# define TEST_LIBASM_H

# include "launcher.h"

/*************************test mandatory*************************/
				/*********test for strlen*********/
int		strlen_launcher(void);
int		strlen_basic_test(void);
int		strlen_null_test(void);
int		strlen_bigger_string_test(void);
int 	strlen_void_test(void);

				/*********test for read*********/
int		read_launcher(void);
int		read_basic_test(void);
int		read_wrond_fd_test(void);
int		read_bigger_string_test(void);

				/*********test for strcmp*********/
int		strcmp_launcher(void);
int		strcmp_diff_test(void);
int		strcmp_basic_test(void);
int		strcmp_null_test(void);
int		strcmp_bigger_string_test(void);

				/*********test for strdup*********/
int		strdup_launcher(void);
int		strdup_basic_test(void);
int		strdup_null_test(void);
int		strdup_bigger_string_test(void);

				/*********test for strcpy*********/
int		strcpy_launcher(void);
int		strcpy_basic_test(void);
int		strcpy_null_test(void);
int		strcpy_bigger_string_test(void);

				/*********test for write*********/
int		write_launcher(void);
int		write_basic_test(void);
int		write_null_test(void);
int		write_bigger_string_test(void);

/*************************test mandatory*************************/

#endif