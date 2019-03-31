/*
 * Write a function that reads a list of integers from the
 * standard input and returns the values in a dynamically
 * allocated array. The end of the input list is determined
 * by watching for EOF. The first number in the array should
 * be a count of how many values the array contains. This
 * number is followed by the values.
 */

#include<stdio.h>
#include<stdlib.h>
#define INT_SIZE	10

int *readints()
{
	int *array, count = 0, size, value, i;
	printf("Enter number\n");

	size = INT_SIZE;
	array = malloc((size + 1) * sizeof(int));
	if (array == NULL) {
		printf("Out of memory\n");
		return NULL;
	}
	
	while( (scanf("%d", &value) == 1)) {
		/* Make the array bigger if needed
		 * then store the value
		 */
		count += 1;

		if (count > size) {
			// Realloc array
			size += INT_SIZE;
			array = realloc(array,
					(size + 1) * sizeof(int));
			if (array == NULL)
				return NULL;
		}
		array[count] = value;
	}

	/* Resize exact size of array */
	if (count < size) {
		array = realloc(array,
				(count + 1) * sizeof(int));
		if (array == NULL)
			return NULL;
	}
	array[0] = count;

	for (i = 0; i <= count; i++)
		printf("%d ", array[i]);
	printf("\n");
}

int main()
{
	readints();
}
