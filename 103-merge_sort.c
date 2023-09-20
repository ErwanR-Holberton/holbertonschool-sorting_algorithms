#include "sort.h"
void merge_function(int *array_copy, int left, int middle, int right, int *array)
{
	int i = left, j = middle, k;

	for (k = left; k < right; k++)
	{
		if (i < middle && (j >= right || array[i] <= array[j]))
		{
			array_copy[k] = array[i];
			i = i + 1;
		}
		else
		{
			array_copy[k] = array[j];
			j = j + 1;
		}
	}
}
void split_merge(int *array, int left, int right, int *array_copy)
{
	int middle;

	if (right - left <= 1)
		return;

	middle = (right + left) / 2;
	split_merge(array, left, middle, array_copy);
	split_merge(array, middle, right, array_copy);

	merge_function(array_copy, left, middle, right, array);
}
/**
 * merge_sort - sort an array using merge top-down algo
 * @array: the array to sort
 * @size: size of the array
*/
void merge_sort(int *array, size_t size)
{
	int *array_copy, i;

	if (array == NULL)
		return;

	array_copy = malloc(sizeof(int) * size);
	for (i = 0; (unsigned) i < size; i++)
		array_copy[i] = array[i];

	split_merge(array, 0, size, array_copy);


	for (i = 0; (unsigned) i < size; i++)
		array[i] = array_copy[i];
	free(array_copy);
}

