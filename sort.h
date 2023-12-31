#ifndef SORT_H
#define SORT_H

#include <stdio.h>
#include <stdlib.h>

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
 typedef struct listint_s
{
    const int n;
    struct listint_s *prev;
    struct listint_s *next;
} listint_t;

/* print utility functions */
void print_array(const int *array, size_t size);
void print_list(const listint_t *list);

/* sort functions */
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void shell_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);

/* swap functions */
void int_swap(int *a, int *b);
void node_swap(listint_t **h, listint_t **n1, listint_t *n2);
void swap_value(int *a, int *b);
void bubble_sort(int *array, size_t size);
void swap(int *a, int *b);

#endif
