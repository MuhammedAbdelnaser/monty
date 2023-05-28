#include "monty.h"

/**
* execute - execute the monty code
* @stack: head linked list - stack
* @line_number: line_line_number
* @file: pointer to monty file
* @content: line content
* Return: no return
*/
int execute(char *content, stack_t **stack, unsigned int line_number,
FILE *file)
{
	instruction_t opList[] = {
				{"pall", s_pall},
				{"push", s_push},
				{"pint", s_pint},
				{"pop", s_pop},
				{"swap", s_swap},
				{"add", s_add},
				{"nop", s_nop},
				{NULL, NULL}
				};
	unsigned int i = 0;
	char *op;

	op = strtok(content, " \n\t");
	if (op && op[0] == '#')
		return (0);

	bus.arg = strtok(NULL, " \n\t");
	while (opList[i].opcode && op)
	{
		if (strcmp(op, opList[i].opcode) == 0)
		{	opList[i].f(stack, line_number);
			return (0);
		}
		i++;
	}
	if (op && opList[i].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_number, op);
		fclose(file);
		free(content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	return (1);
}
