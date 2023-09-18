#include "sort.h"
/**
 * bubble_sort - name of the function
 * Description: use the bubble sort algorithm
 * @array: the array to sort
 * @size: size of the array
*/
void bubble_sort(int *array, size_t size)
{
	int temp;
	size_t pass;
	size_t i;

	for (pass = 0; pass < size; pass++)
	{
		for (i = 0; i < size - 1 - pass; i++)
		{
			if (array[i] > array[i + 1])
			{
				temp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = temp;
				print_array(array, size);
			}
		}
	}
}
