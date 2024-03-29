#include "monty.h"

/**
 * initialize_arguments - Initilaizes the properties of arg_t arguments
*/
void initialize_arguments(void)
{
	arguments = malloc(sizeof(arg_t));
	if (arguments == NULL)
		malloc_error();

	arguments->instruction = malloc(sizeof(instruction_t));
	if (arguments->instruction == NULL)
		malloc_error();

	arguments->head = NULL;
	arguments->stream = NULL;
	arguments->file_name = NULL;
	arguments->line = NULL;
	arguments->n_tokens = 0;
	arguments->ln = 0;
	arguments->stack_length = 0;
	arguments->stack = 1;
}
