#include "monty.h"

/**
 * free_tokens - Free all the tokens and the arrayed toknes
 * Return: void
 */
void free_tokens(void)
{
	int i = 0;

	if (arguments->tokens == NULL)
		return;

	while (arguments->tokens[i] != NULL)
	{
		free(arguments->tokens[i]);
		i++;
	}

	free(arguments->tokens);
	arguments->tokens = NULL;
}



/**
 * close_stream - Close the stream when needed
 * Return: void
 */
void close_stream(void)
{
	if (arguments->stream == NULL)
		return;

	fclose(arguments->stream);
	arguments->stream = NULL;
}



/**
 * free_stack - frees stack and all other head->next
 * @head: The current node
 * Return: void
 */
void free_stack(stack_t *head)
{
	if (head == NULL)
		return;

	if (head->next != NULL)
		free_stack(head->next);

	free(head);
}

/**
 * free_head - Frees the head stack_t
 */
void free_head(void)
{
	if (arguments->head)
		free_stack(arguments->head);

	arguments->head = NULL;
}

/**
 * free_arguments - This frees all the memory allocated to the struct
 * Return: void
 */
void free_arguments(void)
{
	if (arguments == NULL)
		return;

	if (arguments->instruction)
	{
		free(arguments->instruction);
		arguments->instruction = NULL;
	}
	free_head();
	if (arguments->line)
	{
		free(arguments->line);
		arguments->line = NULL;
	}
	
	free(arguments);
}
