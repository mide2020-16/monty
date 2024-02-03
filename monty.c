#include "monty.h"

/**
 * _functions_used - Functions used in main()
 */
void _functions_used(void)
{
	tokenize_line();
	get_instruction();
	run_instruction();
	free_tokens();
}

/**
 * main - Entry point to monty
 * @argc: the arguments count
 * @argv: the vector arguments
 *
 * Return: 0 on Success, 1 on Failure
 */
int main(int argc, char *argv[])
{
	char line[MAX_LINE_LENGTH];
	ssize_t len = 0;

	arguments->file_name = argv[1];
	check_terminal_args(argc);

	initialize_arguments();
	stream_file(arguments->file_name);

	while (fgets(line, MAX_LINE_LENGTH, arguments->stream) != NULL)
	{
		len = strlen(line);
		if (len > 0 && line[len - 1] == '\n')
			line[len - 1] = '\0';

		arguments->ln += 1;
		arguments->line = malloc(len + 1);
		if (arguments->line == NULL)
			malloc_error();

		strcpy(arguments->line, line);

		_functions_used();
		free(arguments->line);
	}
	close_stream();

	free_arguments();
	return (0);
}
