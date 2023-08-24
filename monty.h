#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>
/**
 * struct stack_s - doubly linked list representation of aa stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doulbly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct bus_s - variables
 * @arg: value
 * @file: pontes to the monty
 * @line: line of the content of the file
 * @lifi: that flag change of stack <-> queues
 *
 * Description: process the value through out the program
 */
typedef struct bus_s
{
	char *arg;
	FILE *file;
	char *line;
	int lifi;
} bus_t;

extern bus_t bus;

void ps_push(stack_t **head, unsigned int number);
void s_add_queue(stack_t **head, int n);
void s_add_node(stack_t **head, int n);
void ps_pall(stack_t **head, unsigned int counter);
int _execute(char *line, stack_t **head, unsigned int counter, FILE *file);
void stack_free(stack_t *head);
void ps_swap(stack_t **head, unsigned int counter);
void ps_add(stack_t **head, unsigned int counter);
void e_nop(stack_t **head, unsigned int counter);

#endif
