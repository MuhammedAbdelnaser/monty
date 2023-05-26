#include "monty.h"

/**
 * execute - execute the monty code
 * @content: line content
 * @stack: head linked list - stack
 * @counter: line_counter
 * @file: pointer to monty file
 * Return: 0 on success, 1 on failure
 */
int execute(char *content, my_stack_t **stack, unsigned int counter, FILE *file)
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

    char *op = strtok(content, " \n\t");
    if (op != NULL && op[0] == '#')
        return 0;

    bus.arg = strtok(NULL, " \n\t");
    unsigned int i = 0;
    while (opList[i].opcode != NULL)
    {
        if (strcmp(op, opList[i].opcode) == 0)
        {
            opList[i].f(stack, counter);
            return 0;
        }
        i++;
    }

    if (op != NULL)
    {
        fprintf(stderr, "L%d: unknown instruction %s\n", counter, op);
        fclose(file);
        free(content);
        free_stack(*stack);
        exit(EXIT_FAILURE);
    }

    return 1;
}
