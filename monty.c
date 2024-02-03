#include "monty.h"
#include <stdio.h>

/**
 * main - Entry point to monty
 * @argc: the arguments count
 * @argv: the vector arguments
 *
 * Return: 0 on Success, 1 on Failure
*/
int main(int argc, char *argv[])
{
	ssize_t len = 0;

	arguments->file_name = argv[1];
	check_terminal_args(argc);

	initialize_arguments();
	stream_file(arguments->file_name);

	while (getline(&arguments->line, &len, arguments->stream) != -1)
	{
		arguments->ln += 1;
		tokenize_line();

		get_instruction();
		run_instruction();

		free_tokens();
	}
	close_stream();

	free_arguments();
	return (0);
}
