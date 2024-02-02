#include "monty.h"

/**
 * push - This operation is used to insert a value to a stack
 *
 * @stack:       The instance of the stack
 * @line_number: The line of the operation in the file
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (arguments->n_tokens <= 1 || !(is_number(arguments->tokens[1])))
	{
		free_arguments();
		dprintf(2, "L%d: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	*stack = malloc(sizeof(stack_t));
	if (*stack == NULL)
		malloc_error();

	(*stack)->next = (*stack)->prev = NULL;
	(*stack)->n = (int)atoi(arguments->tokens[1]);

	/*
	Add a list to the beginning of the stack or at the end
	*/
	if (arguments->head != NULL)
	{
		if (arguments->stack)
		{
			(*stack)->next = arguments->head;
			arguments->head->prev = *stack;

			arguments->head = *stack;
		}
		else
		{
			temp = arguments->head;

			while (temp->next)
			{
				temp = temp->next;
				temp->next = *stack;

				(*stack)->prev = temp;
			}
		}
	}
	else
		arguments->head = *stack;

	arguments->stack_length += 1;
}

/**
 * pall - This operation prints all the values in the stack
 *
 * @stack:       The instance of the stack
 * @line_number: The line of the operation in the file
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	(void)stack;
	(void)line_number;

	temp = arguments->head;
	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}
