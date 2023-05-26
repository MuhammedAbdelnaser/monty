#include "monty.h"

/**
 * add - adds the top two elements of the stack
 * @head: stack head
 * @line_number: line_number
 * Return: no return
 */

void fadd(stack_t **head, unsigned int line_number)
{
  stack_t *h;
  int sum;

  h = *head;
  if (h == NULL || h->next == NULL)
  {
    fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
    fclose(bus.file);
    free(bus.content);
    free_stack(*head);
    exit(EXIT_FAILURE);
  }
  sum = h->n + h->next->n;
  h->next->n = sum;
  *head = h->next;
  free(h);
}
