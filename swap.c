#include "monty.h"

/**
 * swap - swaps the top two elements of the stack
 * @head: stack head
 * @line_number: line_number
 * Return: no return
 */

void swap(stack_t **head, unsigned int line_number)
{
  stack_t *h;
  int tmp;

  h = *head;
  if (h == NULL || h->next == NULL)
  {
    fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
    fclose(bus.file);
    free(bus.content);
    free_stack(*head);
    exit(EXIT_FAILURE);
  }
  tmp = h->n;
  h->n = h->next->n;
  h->next->n = tmp;
}
