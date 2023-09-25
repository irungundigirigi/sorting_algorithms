#include "sort.h"

/**
 * int_swap - swaps two integers in an array
 * @a: the first int to swap
 * @b: the second int to swap
 */

void int_swap(int *a, int *b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
	
}

/**
 * selection_sort - sort an array of ints in ascending order
 * @array: An array of ints
 * @size: size of array
 *
 * Description: Prints the array after each swap
 */

void selection_sort(int *array, size_t size)
{
    int *min_value;
    size_t i, j;

    if (array == NULL || size < 2)
        return;

    for (i = 0; i < size - 1; i++)
    {
        min_value = array + i;
        for (j = i + 1; j < size; j++)
            min_value = (array[j] < *min_value) ? (array + j) : min_value;

        if ((array + i) != min_value)
        {
            swap_integers(array + i, min_value);
            print_array(array, size);
        }
    }
}
