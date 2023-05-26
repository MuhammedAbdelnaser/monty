#include "monty.h"

/**
 * div - divides the second top element of the stack by the top element
 * @head: head of the stack
 * @line_number: no used
 * Return: no return
 */

void fdiv(stack_t **head, unsigned int line_number)
{
  stack_t *h;
  int div;

  h = *head;
  if (h == NULL || h->next == NULL)
  {
    fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
    fclose(bus.file);
    free(bus.content);
    free_stack(*head);
    exit(EXIT_FAILURE);
  }
  if (h->n == 0)
  {
    fprintf(stderr, "L%d: division by zero\n", line_number);
    fclose(bus.file);
    free(bus.content);
    free_stack(*head);
    exit(EXIT_FAILURE);
  }
  div = h->next->n / h->n;
  pop(head, line_number);
  (*head)->n = div;
}
