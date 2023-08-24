#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>

typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

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

#endif
