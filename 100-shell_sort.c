#include "sort.h"
/**
 * shell_sort - name of the function
 * Description: using the Shell sort algorithm, using the Knuth sequence
 * @array: the array sorted
 * @size: size of the array
*/
void shell_sort(int array[], int size)
{
	int temp, j, i, interval = 1;

	/* Calcul de l'intervalle selon la séquence de Knuth*/
	while (interval <= size / 3)
	{
		interval = interval * 3 + 1;
	}

	while (interval > 0)
	{


		for (i = interval; i < size; i++)
		{
			temp = array[i];
			j = i;

			/* Tri par insertion */
			while (j >= interval && array[j - interval] > temp)
			{
				array[j] = array[j - interval];
				j -= interval;
			}

			array[j] = temp;
		}
		print_array(array, size);

		interval = (interval - 1) / 3;
	}
}
