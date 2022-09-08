#include "monty.h"

store_t data;

/**
 * main - is the main function of program
 * @argc: number of arguments passed
 * @argv: double pointer to each arg
 * Return: 0 on success 1 on failure
 */
int main(int argc, char **argv)
{
	stack_t *stack;
	ssize_t getline_ret;
	size_t line_size = 0;

	/* output error if no file is given */
	if (argc < 3 || argc > 3)
	{
		fprintf(stderr, "USAGE: monty file");
		exit(EXIT_FAILURE);
	}
	/* store file name in struct store_s */
	data.name_pointer = argv[1];
	/* open and read the monty file */
	data.fp = fopen(data.name_pointer, "r");
	/* output error if cannot open file */
	if (data.fp == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s", data.name_pointer);
		exit(EXIT_FAILURE);
	}

	/* program continues here if none of the errors above is encountered */
	/* reads the line input in program */
	getline_ret = getline(&data.current_line, &line_size, data.fp);
	/* while the line can be successfuly read */
	while (getline_ret != -1)
	{
		/* check if line is empty */
		if (*data.current_line == '\n')
			continue;
		data.line_count += 1;
		/* split the line into args */
		/* parsing function returns 0 on success 1 on failure */
		/* on failure to tokenize */
		if ((strtok_func(data.current_line, delim)) == 1)
		{
			fprintf(stderr, "Failed to split line into arguments");
			exit(EXIT_FAILURE);
		}
		/* check if no args are passed in line */
		if (*data.line_args == NULL)
		{
			fprintf(stderr, "There are no arguments in the line");
			exit(EXIT_FAILURE);
		}
		/* execute the line read */
		execute_line_func(&stack);
	}
	/* free the used struct data members memory */
	free(data.current_line);
	data.current_line = NULL;
	free(data.line_args);
	data.line_args = NULL;

	/* if file is run successfuly */
	/* close the file opened */
	fclose(data.fp);
	return (EXIT_SUCCESS);
}
