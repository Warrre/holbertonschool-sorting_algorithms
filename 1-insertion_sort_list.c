#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 * in ascending order using the Insertion sort algorithm
 * @list: Double pointer to the head of the doubly linked list
 */
void insertion_sort_list(listint_t **list)
{
    listint_t *current, *prev, *next;

    if (list == NULL || *list == NULL || (*list)->next == NULL)
        return;

    current = (*list)->next;
    
    while (current != NULL)
    {
        prev = current->prev;
        next = current->next;

        while (prev != NULL && current->n < prev->n)
        {
            if (prev->prev != NULL)
                prev->prev->next = current;
            else
                *list = current;

            current->prev = prev->prev;

            if (next != NULL)
                next->prev = prev;

            prev->next = next;
            current->next = prev;
            prev->prev = current;

            print_list(*list);
            prev = current->prev;
        }
        current = next;
    }
}
