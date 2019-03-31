/*
 * Read a string from standard input and returns a copy
 * of the string in dynamically allocated memory. The
 * function may not impose any limit on the size of the
 * string being read.
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_STRING	10

char *read_string()
{
	char *str;
	int ch, count = 0, size;

	size = MAX_STRING;

	str = (char *)malloc(size * sizeof(char));
	if (str == NULL) {
		printf("Out of memory\n");
		return NULL;
	}

	while((ch = getchar()) != EOF) {
		str[count] = ch;
		count += 1;
		if (count > size) {
			size += MAX_STRING;
			str = realloc(str,
					size * sizeof(char));
			if (str == NULL) {
				printf("Out of memory for realloc\n");
				return NULL;
			}
		}
	}

	str[count] = '\0';
	str = realloc(str,
			(count + 1) * sizeof(char));
	if (str == NULL) {
		printf("Out of memory for realloc\n");
		return NULL;
	}
	printf("Count %d, len %d\n", count, strlen(str));

	return str;
}

int main()
{
	char *input;

	printf("Enter input(press CTRL ^D to exit)\n");
	input = read_string();
	printf("%s\n", input);
}
