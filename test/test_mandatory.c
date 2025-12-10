// #include "test.h"

// void test_read() {
// 	size_t buff_size = 564;

// 	printf("%s----------------------------------------------------------------------------------\n", YELLOW);
// 	printf("testing read function\n");
// 	printf("----------------------------------------------------------------------------------\n");
// 	printf("Please enter a simple sentence : =>%s\n", RESET);
// 	char *bufasm;
// 	read(0, &bufasm, buff_size);
// }

// void test_write() {
// 	printf("%s----------------------------------------------------------------------------------", YELLOW);
// 	printf("testing write function");
// 	printf("----------------------------------------------------------------------------------\n");
// 	printf("test Write simple text: =>%s\n", RESET);
// 	const char *s = "Hello Wolrd\n";

// 	ssize_t original = write(1, s, strlen(s));
// 	ssize_t retasm = ft_write(1, s, strlen(s));

// 	if (original == retasm) {
// 		printf("%shello world test pass%s\n", GREEN, RESET);
// 	}
// 	else {
// 		printf("%s----------------------------------------------------------------------------------\n", RED);
// 		printf("failed to write hello world :\n");
// 		printf("original = %zd\n", original);
// 		printf("asm write = %zd\n", retasm);
// 		printf("----------------------------------------------------------------------------------%s\n", RESET);
// 	}
// }

// void test_strlen() {

// }

// void test_strcpy() {

// }

// void test_strcmp(){

// }

// void test_strdup() {

// }