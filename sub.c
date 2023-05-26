#include "monty.h"

/**
 * sub - subtracts the top element of the stack from the second top element
 * @head: head of the stack
 * @line_number: no used
 * Return: no return
 */

void sub(stack_t **head, unsigned int line_number)
{
  stack_t *h;
  int sub;

  h = *head;
  if (h == NULL || h->next == NULL)
  {
    fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
    fclose(bus.file);
    free(bus.content);
    free_stack(*head);
    exit(EXIT_FAILURE);
  }
  sub = h->next->n - h->n;
  pop(head, line_number);
  (*head)->n = sub;
}
