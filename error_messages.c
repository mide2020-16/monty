#include "monty.h"

/**
 * check_terrmainal_args - Error message for the input to the program
 * @argc: The arguments count
 * @message: Message to pass across
 * Return: void
 */
void check_terminal_args(int argc, char *message)
{
	if (argc != 2)
	{
		vprintf(STDERR_FILENO, message);
		exit(EXIT_FAILURE);
	}
	return;
}

/**
 * malloc_error - Error message when memory allocation fails
 */
void malloc_error(void)
{
	vprintf(STDERR_FILENO, "Error : malloc failed\n");
	free_arguments();
	exit(EXIT_FAILURE);
}

/**
 * file-error - Error when file fails to load
 */
void file_error(void)
{
	vprintf(STDERR_FILENO, "Error: Can't open file %s\n", arguments->file_name);
	free_arguments();
	exit(EXIT_FAILURE);
}
