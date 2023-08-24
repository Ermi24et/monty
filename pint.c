#include "monty.h"

/**
 * ps_pint - print the top of the stack element
 * @head: the head of the stack
 * @counter: counts the line 
 * Return: void
 */

void ps_pint(stack_t **head, unsigned int counter)
{
	if (*head == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", counter);
		fclose(bus.file);
		free(bus.line);
		stack_free(*head);
		exit(EXIT_FAILURE);
	}
	else
		printf("%d\n", (*head)->n);
}
