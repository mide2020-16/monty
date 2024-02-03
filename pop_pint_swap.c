#include "monty.h"

/**
 * pint - Prints the value of the first node
 *
 * @stack:       The stack
 * @line_number: The line number of the instruction
 */
void pint(stack_t **stack, unsigned int line_number)
{
	(void)stack;

	if (arguments->head == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		free_all_args();
		exit(EXIT_FAILURE);
	}

	printf("%d", arguments->head->n);
}

/**
 * pop - Removes the first node and it's value
 *
 * @stack:       The stack
 * @line_number: The line number of the instruction
 */
void pop(stack_t **stack, unsigned int line_number)
{
	(void)stack;

	if (arguments->head == NULL)
	{
		fprintf(stderr, "L%d: can't pop a empty stack\n", line_number);
		free_all_args();
		exit(EXIT_FAILURE);
	}

	delete_node();
	arguments->stack_length -= 1;
}

/**
 * swap - Swaps the position two nodes
 *
 * @stack:       The stack
 * @line_number: The line number of the instruction
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *node1, *node2;

	(void)stack;
	if (arguments->stack_length < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		free_all_args();
		exit(EXIT_FAILURE);
	}

	node1 = arguments->head;
	node2 = arguments->head->next;

	node1->next = node2->next;
	if (node1->next)
		node1->next->prev = node1;

	node2->next = node1;
	node1->prev = node2;

	node2->prev = NULL;
	arguments->head = node2;
}
