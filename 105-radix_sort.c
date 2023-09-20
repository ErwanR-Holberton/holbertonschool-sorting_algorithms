#include "sort.h"
/**
 * make_array - name of the function
 * Description: make a temporary array
 * @array: the origin array
 * @array: size of the origin array
 * @nb_digits: number of digits of the maximum value
*/
void make_array(int *array, size_t size, int nb_digits)
{
	int array_temp[size], i, j, number, k;
	int puissance = 1;
	int count[10];

	for (i = 0; i < nb_digits; i++)
	{
		for (k = 0; k < 10; k++)
			count[k] = 0;

		for (j = 0; j < (int)size; j++)
		{
			number = (array[j] / puissance) % 10;
			count[number]++;
		}

		for (j = 1; j < 10; j++)
		{
			count[j] += count[j - 1];
		}

		for (j = size - 1; j >= 0; j--)
		{
			number = (array[j] / puissance) % 10;
			array_temp[count[number] - 1] = array[j];
			count[number]--;
		}
		for (j = 0; j < (int)size; j++)
		{
			array[j] = array_temp[j];
		}
		puissance *= 10;
		print_array(array, size);
	}
}
/**
 * countDigits - name of the function
 * Description: count the number of digits
 * @number: the number
 * Return: return the number of digits
 */
int countDigits(int number)
{
	int count = 0;

	while (number != 0)
	{
		number /= 10;
		count++;
	}
	return count;
}
/**
 * radix_sort - name of the function
 * Description: using the radix sort algorithm
 * @array: the array sorted
 * @size: size of the array
 */
void radix_sort(int *array, size_t size)
{
	int max = 0;
	int nb_digits;
	size_t i;

	if (array == NULL || size == 0)
		return;

	for (i = 0; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	nb_digits = countDigits(max);
	make_array(array, size, nb_digits);
}
