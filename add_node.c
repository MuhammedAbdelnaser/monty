#include "monty.h"

/**
 * add_node - add node to the head stack
 * @head: head of the stack
 * @n: new_value
 * Return: no return
 */
void add_node(my_stack_t **head, int n)
{
    my_stack_t *new_node = malloc(sizeof(my_stack_t));
    if (new_node == NULL)
    {
        printf("Error\n");
        exit(0);
    }

    new_node->n = n;
    new_node->next = *head;
    new_node->prev = NULL;

    if (*head != NULL)
        (*head)->prev = new_node;

    *head = new_node;
}
