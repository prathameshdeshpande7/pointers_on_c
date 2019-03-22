#include<stdio.h>
#include<string.h>

size_t my_strnlen(char *dst, int size)
{
	size_t length;

	for (length = 0; length < size; length++)
	{
		if (*dst++ == '\0')
			break;
	}
	return length;
}

int main()
{
	char src[35] = "Copy only specific characters";
	char dst[15] = "this much";
	int length;

	strncpy(dst, src, 10);

	length = my_strnlen(dst, 10);
	printf("Dst: %s, length %d\n", dst, length);
	return 0;
}
