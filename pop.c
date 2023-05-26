#include "monty.h"

/**
 * pop - removes the top element of the stack
 * @head: head of the stack
 * @line_number: no used
 * Return: no return
 */

void pop(stack_t **head, unsigned int line_number)
{
  stack_t *h;

  h = *head;
  if (h == NULL)
  {
    fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
    fclose(bus.file);
    free(bus.content);
    free_stack(*head);
    exit(EXIT_FAILURE);
  }
  *head = h->next;
  if (h->next)
    h->next->prev = NULL;
  free(h);
}
