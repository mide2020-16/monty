#include "monty.h"

/**
 * add - Adds the value of two nodes together
 *
 * @stack:       The stack
 * @line_number: The line number of the instruction
 */
void add(stack_t **stack, unsigned int line_number)
{
	stack_t *node1, *node2;

	(void)stack;
	if (arguments->stack_length < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		free_all_args();
		exit(EXIT_FAILURE);
	}

	node1 = arguments->head;
	node2 = arguments->head->next;

	node2->n = node1->n + node2->n;
	delete_node();

	arguments->stack_length -= 1;
}

/**
 * sub - Subtracts the value of two nodes from each other
 *
 * @stack:       The stack
 * @line_number: The line number of the instruction
 */
void sub(stack_t **stack, unsigned int line_number)
{
	stack_t *node1, *node2;

	(void)stack;

	if (arguments->stack_length < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		free_all_args();
		exit(EXIT_FAILURE);
	}

	node1 = arguments->head;
	node2 = arguments->head->next;

	node2->n = node2->n - node1->n;

	delete_node();
	arguments->stack_length -= 1;
}

/**
 * mul - Multiplies two values together
 *
 * @stack:       The stack
 * @line_number: The line number of the instruction
 */
void mul(stack_t **stack, unsigned int line_number)
{
	stack_t *node1, *node2;

	(void)stack;

	if (arguments->stack_length < 2)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		free_all_args();
		exit(EXIT_FAILURE);
	}

	node1 = arguments->head;
	node2 = arguments->head->next;

	node2->n = node2->n * node1->n;

	delete_node();
	arguments->stack_length -= 1;
}

/**
 * div - Divides the value of two nodes from each other
 *
 * @stack:       The stack
 * @line_number: The line number of the instruction
 */
void _div(stack_t **stack, unsigned int line_number)
{
	stack_t *node1, *node2;

	(void)stack;
	if (arguments->stack_length < 2)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		free_all_args();
		exit(EXIT_FAILURE);
	}

	node1 = arguments->head;
	node2 = arguments->head->next;

	if (node1->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		free_all_args();
		exit(EXIT_FAILURE);
	}

	node2->n = node2->n / node1->n;
	delete_node();

	arguments->stack_length -= 1;
}

/**
 * mod - Finds the mod of two values
 *
 * @stack:       The stack
 * @line_number: The line number of the instruction
 */
void mod(stack_t **stack, unsigned int line_number)
{
	stack_t *node1, *node2;

	(void)stack;

	if (arguments->stack_length < 2)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		free_all_args();
		exit(EXIT_FAILURE);
	}

	node1 = arguments->head;
	node2 = arguments->head->next;

	if (node1->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		free_all_args();
		exit(EXIT_FAILURE);
	}
	node2->n = node2->n % node1->n;

	delete_node();
	arguments->stack_length -= 1;
}
