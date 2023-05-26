#include "monty.h"

/**
 * s_pop - removes the top element of the stack
 * @head: stack head
 * @counter: line_number
 * Return: no return
 */
void s_pop(my_stack_t **head, unsigned int counter)
{
    if (*head == NULL)
    {
        fprintf(stderr, "L%d: can't pop an empty stack\n", counter);
        fclose(bus.file);
        free(bus.content);
        free_stack(*head);
        exit(EXIT_FAILURE);
    }
    
    my_stack_t *h = *head;
    *head = h->next;
    free(h);
}
