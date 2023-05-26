#include "monty.h"

/**
 * s_pall - prints the stack
 * @head: stack head
 * @counter: unused
 * Return: no return
 */
void s_pall(my_stack_t **head, unsigned int counter)
{
    my_stack_t *h = *head;
    (void)counter;

    while (h != NULL)
    {
        printf("%d\n", h->n);
        h = h->next;
    }
}
