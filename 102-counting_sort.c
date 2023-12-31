#include "sort.h"
/**
 * counting_sort - name of the function
 * Description: using the counting sort algorithm
 * @array: the array sorted
 * @size: size of the array
 */
void counting_sort(int *array, size_t size)
{
	size_t i;
	int *array_temp;
	int j, number = 0, max = 0;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	array_temp = malloc(sizeof(int) * (max + 1));

	if (array_temp == NULL)
		return;

	for (j = 0; j < max + 1; j++)
	{
		for (i = 0; i < size; i++)
		{
			if (j == array[i])
				number++;
		}
		array_temp[j] = number;
	}
	print_array(array_temp, max + 1);
	i = 0;
	for (j = 0; j < max + 1; j++)
	{
		if (array_temp[j] > array_temp[j - 1])
		{
			array[i] = j;
			i++;
		}
	}
	free(array_temp);
}
