#include "monty.h"

/**
 * is_number - Checks if the string is a number
 * @str: The string
 * Return: 1 if it is a number or 0 if it is not
 */
int is_number(char *str)
{
	int i = 0;

	while (str[i])
	{
		while (i == 0 && str[i] == '-' && str[i + 1])
		{
			i++;
			continue;
		}

		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

