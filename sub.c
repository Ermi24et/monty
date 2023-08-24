#include "monty.h"

/**
 *ps_sub - subsruction
 *@head: head of the stack
 *@counter: counts line number
 *Return: void
 */

void ps_sub(stack_t **head, unsigned int counter)
{
	stack_t *aux;
	int res, node;

	aux = *head;
	for (node = 0; aux != NULL; node++)
		aux = aux->next;
	if (node < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", counter);
		fclose(bus.file);
		free(bus.line);
		stack_free(*head);
		exit(EXIT_FAILURE);
	}
	aux = *head;
	res = aux->next->n - aux->n;
	aux->next->n = res;
	*head = aux->next;
	free(aux);
}
