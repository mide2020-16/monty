#include "monty.h"

/**
 * stack - This operation checks if instruction says stack
 * @stack:       The instance of the stack
 * @line_number: The line of the operation in the file
 */
void stack(stack_t **stack, unsigned int line_number)
{
        (void)stack;
        (void)line_number;

        arguments->stack = 1;
}


/**
 * queue - This operation checks if instruction says queue
 *
 * @stack:       The instance of the stack
 * @line_number: The line of the operation in the file
 */
void queue(stack_t **stack, unsigned int line_number)
{
        (void)stack;
        (void)line_number;

        arguments->stack = 0;
}
