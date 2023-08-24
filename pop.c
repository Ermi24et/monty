#include "monty.h"

/**
 * ps_pop - removes the tops of the element of the stack
 * @head: the head of the stack
 * @counter: counts the line
 * Return: void
 */

void ps_pop(stack_t **head, unsigned int counter)
{
	stack_t *h;

	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", counter);
		fclose(bus.file);
		free(bus.line);
		stack_free(*head);
		exit(EXIT_FAILURE);
	}
	else
	{
		h = *head;
		*head = h->next;
		free(h);
	}
}
