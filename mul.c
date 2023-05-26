#include "monty.h"

/**
 * mul - multiplies the second top element of the stack with the top element
 * @head: head of the stack
 * @line_number: no used
 * Return: no return
 */

void mul(stack_t **head, unsigned int line_number)
{
  stack_t *h;
  int mul;

  h = *head;
  if (h == NULL || h->next == NULL)
  {
    fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
    fclose(bus.file);
    free(bus.content);
    free_stack(*head);
    exit(EXIT_FAILURE);
  }
  mul = h->next->n * h->n;
  pop(head, line_number);
  (*head)->n = mul;
}
