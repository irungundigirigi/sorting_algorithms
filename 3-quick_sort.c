#include "sort.h"

void swapIntegers(int *first, int *second);
int lomutoPartition(int *array, size_t size, int left, int right);
void lomutoQuickSort(int *array, size_t size, int left, int right);
void quickSort(int *array, size_t size);

/**
 * swapIntegers - Swap two integers in an array.
 * @first: The first integer to swap.
 * @second: The second integer to swap.
 */
void swapIntegers(int *first, int *second)
{
    int tmp;

    tmp = *first;
    *first = *second;
    *second = tmp;
}

/**
 * lomutoPartition - Order a subset of an array of integers according to
 *                   the Lomuto partition scheme (last element as pivot).
 * @array: The array of integers.
 * @size: The size of the array.
 * @left: The starting index of the subset to order.
 * @right: The ending index of the subset to order.
 *
 * Return: The final partition index.
 */
int lomutoPartition(int *array, size_t size, int left, int right)
{
    int *pivot, above, below;

    pivot = array + right;
    for (above = below = left; below < right; below++)
    {
        if (array[below] < *pivot)
        {
            if (above < below)
            {
                swapIntegers(array + below, array + above);
                printArray(array, size);
            }
            above++;
        }
    }

    if (array[above] > *pivot)
    {
        swapIntegers(array + above, pivot);
        printArray(array, size);
    }

    return above;
}

/**
 * lomutoQuickSort - Implement the quicksort algorithm through recursion.
 * @array: An array of integers to sort.
 * @size: The size of the array.
 * @left: The starting index of the array partition to order.
 * @right: The ending index of the array partition to order.
 *
 * Description: Uses the Lomuto partition scheme.
 */
void lomutoQuickSort(int *array, size_t size, int left, int right)
{
    int part;

    if (right - left > 0)
    {
        part = lomutoPartition(array, size, left, right);
        lomutoQuickSort(array, size, left, part - 1);
        lomutoQuickSort(array, size, part + 1, right);
    }
}

/**
 * quicksort - Sort an array of integers in ascending order using the
 *             quicksort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Uses the Lomuto partition scheme. Prints the array after
 * each swap of two elements.
 */
void quick_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    lomutoQuickSort(array, size, 0, size - 1);
}

