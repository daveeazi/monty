#ifndef MONTY_H
#define MONTY_H

#define delim "\n\t\a"
#define _GNU_SOURCE

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <unistd.h>
/**
 * struct stack_s - doubly linked list rep of a stack
 * @n: integer
 * @prev: points to prev element of stack
 * @next: points to next element of stack
 * Description: doubly linked list of node struct
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
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct store_s - stores data input in stack
 * @current_line: current line run in monty file
 * @line_args: arguments split in the line
 * @name_pointer: pointer to the file name
 * @line_count: number of lines in the monty file
 * @fp: points to file opened
 * Description: data captured from input of user
 * into the stack
 */
typedef struct store_s
{
	char *current_line;
	char **line_args;
	char *name_pointer;
	unsigned int line_count;
	FILE *fp;
} store_t;
extern store_t data;

/* Monty file handler functions */
int execute_line_func(stack_t **stack);
int strtok_func(char *str, char *del);
int int_check(char *str);

/* Monty Functions implementations */
void push_implem_fnc(stack_t **stack, unsigned int line_number);
void pall_implem_fnc(stack_t **stack,
		unsigned int line_number __attribute__((unused)));
void pint_implem_fnc(stack_t **stack, unsigned int line_number);

#endif
