#include "monty.h"

/**
 *s_add_node - adds node to the top head of the stack
 *@head: head of the stack
 *@n: value of the stack
 *Return: void
 */

void s_add_node(stack_t **head, int n)
{
	stack_t *new_node, *aux;

	aux = *head;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(0);
	}
	if (aux)
	{
		aux->prev = new_node;
	}
	new_node->n = n;
	new_node->next = *head;
	new_node->prev = NULL;
	*head = new_node;
}
