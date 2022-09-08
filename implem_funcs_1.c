#include "monty.h"

void push_implem_fnc(stack_t **stack, unsigned int line_number);
void pall_implem_fnc(stack_t **stack,
		unsigned int line_number __attribute__((unused)));
void pint_implem_fnc(stack_t **stack, unsigned int line_number);

/**
 * push_implem_fnc - function that pushes an element into a stack
 * @stack: stack to insert the element
 * @line_number: line in which opcode is read
 * Return: void
 */
void push_implem_fnc(stack_t **stack, unsigned int line_number)
{
	int int_check_res;
	stack_t *node;

	node = malloc(sizeof(stack_t));
	if (node == NULL)
	{
		fprintf(stderr, "Failed to allocate memory to new node element");
		exit(EXIT_FAILURE);
	}
	int_check_res = int_check(data.line_args[1]);
	line_number = data.line_count;
	if (int_check_res == 0 || data.line_args[1] == NULL)
	{
		fprintf(stderr, "L%d: usage: push integer", line_number);
		exit(EXIT_FAILURE);
	}
	node->n = atoi(data.line_args[1]);
	if (*stack == NULL)
	{
		node->prev = NULL;
		node->next = NULL;
	}
	else
	{
		(*stack)->prev = node;
		node->next = *stack;
		node->prev = NULL;
	}
	*stack = node;
}

/**
 * pall_implem_fnc - prints all values in the stack starting from top
 * @stack: stack whose elements are to be printed
 * @line_number: line in which opcode is
 * Return: void
 */
void pall_implem_fnc(stack_t **stack,
		unsigned int line_number __attribute__((unused)))
{
	stack_t *ptr;

	ptr = (*stack)->next;
	while (ptr)
	{
		printf("%d\n", ptr->n);
		ptr = ptr->next;
	}
}

/**
 * pint_implem_fnc - prints the value at the top of the stack
 * @stack: stack to be accessed
 * @line_number: line which has the opcode
 * Return: void
 */
void pint_implem_fnc(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->next->n);
}
