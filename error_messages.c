#include "monty.h"

/**
 * check_terrmainal_args - Error message for the input to the program
 * @argc: The arguments count
 * @message: Message to pass across
 * Return: void
 */
/**
 * check_terminal_args - a Function that ...
 * @argc: Description of argc.
 * Return: Description of the return value.
 */
void check_terminal_args(int argc)
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	return;
}

/**
 * malloc_error - Error message when memory allocation fails
 */
void malloc_error(void)
{
	fprintf(stderr, "Error : malloc failed\n");
	free_arguments();
	exit(EXIT_FAILURE);
}

/**
 * file-error - Error when file fails to load
 */
/**
 * file_error - a Function that ...
 * Return: Description of the return value.
 */
void file_error(void)
{
	fprintf(stderr, "Error: Can't open file %s\n", arguments->file_name);
	free_arguments();
	exit(EXIT_FAILURE);
}

