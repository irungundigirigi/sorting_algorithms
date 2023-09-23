#include "sort.h"

/**
 * swap_value - swap value in array
 * @a: first value
 * @b: second value
 */

void swap_value(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * bubble_sort - sort an array of ints in ascending order.
 * @array: array to sort
 * @size: array size
 *
 * Description: print array after every swap
 */

void bubble_sort(int *array, size_t size)
{
	size_t i, len = size;
	int break = 0;

	if (array == NULL || size < 2)
		return;

	while (break == 0)
	{
		break = 1;
		for (i = 0; i < len - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				swap_value(array + i, array + i + 1);
				print_array(array, size);
				break = 0;
			}	
		}
		len--;
	}
}
