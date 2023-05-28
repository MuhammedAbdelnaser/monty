#include "monty.h"

bus_t bus = {NULL, NULL, NULL, 0};

/**
* main - monty code interpreter
* @argc: number of arguments
* @argv: monty file location
* Return: 0 on success
*/
int main(int argc, char *argv[])
{
	ssize_t read_line = 1;
	size_t size = 0;
	unsigned int line_number = 0;
	stack_t *stack = NULL;
	FILE *file;
	char *cont;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	bus.file = file;
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while (read_line > 0)
	{
		cont = NULL;
		read_line = getline(&cont, &size, file);
		bus.cont = cont;
		line_number++;
		if (read_line > 0)
		{
			execute(cont, &stack, line_number, file);
		}
		free(cont);
	}
	free_stack(stack);
	fclose(file);
	return (0);
}
