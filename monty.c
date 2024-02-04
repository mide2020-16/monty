#include "monty.h"


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

	initialize_arguments();
	check_terminal_args(argc);
	arguments->file_name = argv[1];
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
		tokenize_line();
		get_instruction();
		run_instruction();
		free_tokens();
		free(arguments->line);
	}
	close_stream();

	free_arguments();
	return (0);
}
