#include "monty.h"

int int_check(char *str);

/**
 * int_check - function to check if arg is integer
 * and convert if not
 * @str: arg to check
 * Return: 0 if integer 1 if not
 */
int int_check(char *str)
{
	int i;

	if (str[0] == '-')
		i = 1;
	for (; str[i] != 0; i++)
	{
		if (!isdigit(str[i]))
			return (1);
	}
	return (0);
}
