#include "monty.h"

/**
 *stack_free - freeing a doubly liked list
 *@head: head of the stack
 *Return: void
 */

void stack_free(stack_t *head)
{
	stack_t *aux;

	aux = head;
	while (head)
	{
		aux = head->next;
		free(head);
		head = aux;
	}
}
