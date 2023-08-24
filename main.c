#define _GNU_SOURCE
#include "monty.h"

bus_t bus = {NULL, NULL, NULL, 0};

/**
 *main - monty code interpreter
 *@ac: number of arguments
 *@av: monty file location
 *Return: 0 on success
 */

int main(int ac, char *av[])
{
	char *line = NULL;
	FILE *file;
	size_t len = 0;
	ssize_t read_line;
	stack_t *stack = NULL;
	unsigned int counter = 0;

	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(av[1], "r");
	bus.file = file;
	if (!file)
	{
		fprintf(stderr, "ERROR: can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}
	while (read_line > 0)
	{
		line = NULL;
		read_line = (getline(&line, &len, file));
		bus.line = line;
		counter++;
		if (read_line > 0)
		{
			_execute(line, &stack, counter, file);
		}
		free(line);
	}
	stack_free(stack);
	fclose(file);
return (0);
}
