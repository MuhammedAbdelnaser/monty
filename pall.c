#include "monty.h"

/**
 * s_pall - prints the stack
 * @head: stack head
 * @line_number: no used
 * Return: no return
*/
void s_pall(stack_t **head, unsigned int line_number)
{
	stack_t *h;
	(void)line_number;

	h = *head;
	if (h == NULL)
		return;
	while (h)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
}
