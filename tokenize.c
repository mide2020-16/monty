#include "monty.h"

/**
 * tokenize_line - This tokenize the current line
 * form the file and get the number of words in
 * the line and also pass each word to it's own array
 */
void tokenize_line(void)
{
	int i = 0;
	char *token = NULL, *delimiters = " \n", *copy_line = NULL;

	copy_line = malloc(sizeof(char) * strlen(arguments->line) + 1);
	strcpy(copy_line, arguments->line);

	token = strtok(copy_line, delimiters);
	while (token)
	{
		arguments->n_tokens += 1;
		token = strtok(NULL, delimiters);
	}

	arguments->tokens = malloc(sizeof(char *) * (arguments->n_tokens + 1));
	strcpy(copy_line, arguments->line);

	token = strtok(copy_line, delimiters);
	while (token)
	{
		arguments->tokens[i] = malloc(sizeof(char) * strlen(token) + 1);
		if (arguments->tokens[i] == NULL)
			malloc_error();

		strcpy(arguments->tokens[i], token);
		token = strtok(NULL, delimiters);

		i++;
	}

	arguments->tokens[i] = NULL;
	free(copy_line);
}

