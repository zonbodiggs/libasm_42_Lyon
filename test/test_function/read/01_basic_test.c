#include "libasm.h"
#include <fcntl.h>

static char	*charge_function(ssize_t(*function)(int fd, void *buff, size_t count), ssize_t *size) {
	int fd = open("test/test_function/read/test.txt", O_RDONLY);
	static char buff[1024];

	if (fd == -1) {
		printf("There is no fd\n");
		return (NULL);
	}
	*size = (*function)(fd, buff, sizeof(buff) - 1);
	close(fd);
	buff[strlen(buff) + 1] = '\0';
	return (buff);
}

void	create_file(void) {
	int fd = open("test/test_function/read/test.txt", O_TRUNC | O_CREAT | O_WRONLY, 0644);

	if (fd == -1) {
		printf("There is no fd\n");
		exit(-1);
	}
	write(fd, "Hello World!", strlen("Hello World!"));
	close(fd);
}

int	read_basic_test(void) {
	create_file();
	ssize_t size_real = 0;
	ssize_t size_assembly = 0;

	char *buff_real = charge_function(&read, &size_real);
	char *buff_assembly = charge_function(&ft_read, &size_assembly);
	
	remove("test/test_function/read/test.txt");
	if (buff_real && buff_assembly && strcmp(buff_real, buff_assembly) == 0 && size_real == size_assembly)
		return (0);
	return (-1);
}
