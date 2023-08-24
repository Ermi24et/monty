#include "monty.h"

/**
 *_execute - executes the opcode
 *@line: line pointer
 *@stack: head of linked list
 *@counter: line number counter
 *@file: pointer to monty file
 *Return: 0 on success, otherwise 1
 */

int _execute(char *line, stack_t **stack, unsigned int counter, FILE *file)
{
	instruction_t opst[] = {{"push", ps_push}, {"pall", ps_pall}};
	unsigned int i = 0;
	char *op;

	op = strtok(line, " \n\t");
	if (op && op[0] == '#')
		return (0);
	bus.arg = strtok(NULL, " \n\t");
	while (opst[i].opcode && op)
	{
		if (strcmp(op, opst[i].opcode) == 0)
		{
			opst[i].f(stack, counter);
			return (0);
		}
		i++;
	}
	if (op && opst[i].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", counter, op);
		fclose(file);
		free(line);
		stack_free(*stack);
		exit(EXIT_FAILURE);
	}
	return (1);
}
