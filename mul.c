#include "monty.h"

/**
 *ps_mul - multiplies the top two elements
 *@head: stack head
 *@counter: counts line numbers
 *Return: void
 */

void ps_mul(stack_t **head, unsigned int counter)
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
		fprintf(stderr, "L%d: can't mul, stack too short\n", counter);
		fclose(bus.file);
		free(bus.line);
		stack_free(*head);
		exit(EXIT_FAILURE);
	}
	_h = *head;
	aux = _h->next->n * _h->n;
	_h->next->n = aux;
	*head = _h->next;
	free(_h);
}
