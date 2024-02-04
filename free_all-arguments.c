#include "monty.h"

/**
 * free_all_args - Closes file, free tokens and free arguments
 */
void free_all_args(void)
{
	close_stream();
	free_tokens();
	free_arguments();
}

