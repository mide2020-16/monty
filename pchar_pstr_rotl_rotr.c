#include "monty.h"

/**
 * pchar - This operation prints a single character
 *
 * @stack:       The instance of the stack
 * @line_number: The line of the operation in the file
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	stack_t *node;

	(void)stack;
	if (arguments->head == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		free_all_args();
		exit(EXIT_FAILURE);
	}

	node = arguments->head;
	if (node->n < 0 || node->n > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		free_all_args();
		exit(EXIT_FAILURE);
	}

	printf("%c\n", node->n);
}

/**
 * pstr - This operation prints a string
 *
 * @stack:       The instance of the stack
 * @line_number: The line of the operation in the file
 */
void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *node;

	(void)stack;
	(void)line_number;

	node = arguments->head;
	while (node != NULL)
	{
		if (node->n <= 0 || node->n > 127)
			break;

		printf("%c", node->n);
		node = node->next;
	}

	printf("\n");
}


/**
 * rotl - This operation rotates the nodes from bottom to top
 *
 * @stack:       The instance of the stack
 * @line_number: The line of the operation in the file
 */
void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *node1, *node2;

	(void)stack;
	(void)line_number;

	if (arguments->stack_length < 2)
		return;

	node1 = arguments->head;
	node2 = arguments->head->next;

	arguments->head = node2;
	while (node2)
	{
		if (node2->next == NULL)
		{
			node2->next = node1;
			node1->next = NULL;

			node1->prev = node2;
			break;
		}

		node2 = node2->next;
	}
}

/**
 * rotr - This operation rotates the nodes from top to bottom
 *
 * @stack:       The instance of the stack
 * @line_number: The line of the operation in the file
 */
void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *node, *last;

	(void)stack;
	(void)line_number;

	if (arguments->stack_length < 2)
		return;

	node = arguments->head;

	while (node)
	{
		if (node->next == NULL)
		{
			last = node;
			break;
		}
		node = node->next;
	}

	last->prev->next = NULL;
	last->next = arguments->head;

	last->prev = NULL;
	arguments->head = last;
}

