#include "libasm.h"
#include <fcntl.h>

static char	*read_file(void) {
	int fd = open("test/test_function/write/test.txt", O_RDONLY);
	static char buff[1024];

	if (fd == -1) {
		printf("There is no fd\n");
		return (NULL);
	}
	read(fd, buff, sizeof(buff) - 1);
	close(fd);
	buff[strlen(buff) + 1] = '\0';
	return (buff);
}

static char	*charge_function(ssize_t(*function)(int fd, const void *buff, size_t count), ssize_t *size) {
	int fd = open("test/test_function/write/test.txt", O_TRUNC | O_CREAT | O_WRONLY, 0644);

	if (fd == -1) {
		printf("There is no fd\n");
		exit(-1);
	}
	*size = (*function)(fd, "Hello World!", strlen("Hello World!"));
	close(fd);
	return (read_file());
}

int	write_basic_test(void) {
	ssize_t size_real = 0;
	ssize_t size_assembly = 0;

	char *buff_real = charge_function(&write, &size_real);
	char *buff_assembly = charge_function(&ft_write, &size_assembly);
	
	remove("test/test_function/write/test.txt");
	// printf("write is : %s, ft_write is: %s\n", buff_real, buff_assembly);
	if (strcmp(buff_real, buff_assembly) == 0 && size_real == size_assembly)
		return (0);
	return (-1);
}