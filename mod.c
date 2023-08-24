#include "monty.h"

/**
 *ps_mod - computes the rest of the division of the second
 *@head: stack head
 *@counter: counts line of number
 *Return: void
 */

void ps_mod(stack_t **head, unsigned int counter)
{
	stack_t *_h;
	int length = 0, aux;

	_h = *head;
	while (_h)
	{
		_h = _h->next;
		length++;
	}
	if (length < 2)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", counter);
		fclose(bus.file);
		free(bus.line);
		stack_free(*head);
		exit(EXIT_FAILURE);
	}
	_h = *head;
	if (_h->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", counter);
		fclose(bus.file);
		free(bus.line);
		stack_free(*head);
		exit(EXIT_FAILURE);
	}
	aux = _h->next->n % _h->n;
	_h->next->n = aux;
	*head = _h->next;
	free(_h);
}
