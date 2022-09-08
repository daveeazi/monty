#include "monty.h"

int execute_line_func(stack_t **stack);
int strtok_func(char *str, char *del);

/**
 * execute_line_func - function that runs the line instruction
 * @stack: double pointer to the stack which is manipulated
 * Return: 0 on success, 1 on failure
 */
int execute_line_func(stack_t **stack)
{
	instruction_t implem_funcs[] = {
		{"push", push_implem_fnc},
		{"pall", pall_implem_fnc},
		{"pint", pint_implem_fnc},
	};
	int i;

	for (i = 0; (implem_funcs + i)->opcode; i++)
	{
		if (strcmp((implem_funcs + i)->opcode, *data.line_args) == 0)
		{
			(implem_funcs + i)->f(stack, data.line_count);
			return (EXIT_SUCCESS);
		}
	}
	fprintf(stderr, "An error occured during execution");
	return (EXIT_FAILURE);
}

/**
 * strtok_func - tokenize and split the line into args
 * @str: the string of line to be split
 * @del: the delimiter char
 * Return: 0 on success 1 on failure
 */
int strtok_func(char *str, char *del)
{
	char *token;
	size_t n, i, max_size = 4;

	data.line_args = malloc(max_size * sizeof(char *));
	if (data.line_args == NULL)
	{
		fprintf(stderr, "The line is empty");
		exit(EXIT_FAILURE);
	}
	token = strtok(str, del);
	i = 0;
	while (token)
	{
		data.line_args[i++] = token;
		if (i >= max_size)
		{
			n = max_size * 2;
			free(data.line_args);
			data.line_args = malloc(n * sizeof(char *));
			if (data.line_args == NULL)
			{
				fprintf(stderr, "Failed to allocate memory space");
				exit(EXIT_FAILURE);
			}
			max_size = n;
		}
		token = strtok(NULL, delim);
	}
	data.line_args[i] = NULL;
	return (EXIT_SUCCESS);
}
