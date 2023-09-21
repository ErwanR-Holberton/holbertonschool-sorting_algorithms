#include "sort.h"
/**
 * swap - swap two values
 * @array: array to sort
 * @i: index of value to swap
 * @j: index of second value to swap
 * @size: size of the array
 * Return: pivot index
*/
void swap(int *array, int i, int j, int size)
{
	int temp;

	if (i != j)
	{
		temp = array[i];
		array[i] = array[j];
		array[j] = temp;
		print_array(array, size);
	}
}
/**
 * partition - make a partition and return pivot index
 * @array: array to sort
 * @left: boundary to the left
 * @right: boundary to the right
 * @size: size of the array
 * Return: pivot index
*/
int partition(int *array, int left, int right, int size)
{
	int pivot = array[right], i = left - 1, j;

	for (j = left; j <= right - 1; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			swap(array, i, j, size);
		}
	}
	i++;
	swap(array, i, right, size);
	return (i);
}

/**
 * quicksort_custom - sort list using quick sort algorithm
 * @array: array to sort
 * @left: boundary to the left
 * @right: boundary to the right
 * @size: size of the array
*/
void quicksort_custom(int *array, int left, int right, int size)
{
	int p;

	if (left >= right || left < 0)
		return;

	p = partition(array, left, right, size);

	quicksort_custom(array, left, p - 1, size);
	quicksort_custom(array, p + 1, right, size);
}
/**
 * quick_sort - sort list using quick sort algorithm
 * @array: array to sort
 * @size: size of the array
*/
void quick_sort(int *array, size_t size)
{
	unsigned int i;

	if (array == NULL)
		return;
	for (i = 0; i < size - 1; i++)
		if (array[i] > array[i + 1])
		{
			quicksort_custom(array, 0, size - 1, size);
			break;
		}

}


