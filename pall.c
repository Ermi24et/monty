#include "monty.h"

/**
 *ps_pall - prints the stack
 *@head: head of the stack
 *@counter: counts integer
 *Return: void
 */

void ps_pall(stack_t **head, unsigned int counter)
{
	stack_t *h;
	(void)counter;

	h = *head;
	if (h == NULL)
		return;
	while (h)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
}
