#ifndef MONTY_H
#define MONTY_H

/**
 * Standard Libraries for MONTY
*/
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024 * 8

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 *
 * @n:    Integer
 * @prev: Points to the previous element of the stack (or queue)
 * @next: Points to the next element of the stack (or queue)
 *
 *
 * Description: Doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;


/**
 * struct instruction_s - opcode and its function
 *
 * @opcode: The opcode
 * @f:      Function to handle the opcode
 *
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * arg_s -        Stream of a file and each line in the file
 *
 * @head:         The head of the stack
 * @stream:       The stream to the file
 * @file_name:    The file name
 * @line:         A single line from the file
 * @tokens:       Contents in the line
 * @n_tokens:     Number of words in the line
 * @ln:           The line number of the current line
 * @stack:        Checks if it is a stack or queue
 * @stack_length: The number of nodes in the stack
 * @instruction:  The instruction to execute
 *
 *
 * Description:   Create a struct called args that would
 * store the data/info read from a line of a stream
 */
typedef struct arg_s
{
	stack_t *head;
	FILE *stream;
	char *file_name;
	char *line;
	char **tokens;
	int n_tokens;
	unsigned int ln;
	int stack;
	int stack_length;
	instruction_t *instruction;
} arg_t;



/**
 * Global variables
*/
extern arg_t *arguments;


/**
 * initialize_arguments.c
 * Initializes all the prop of arg_t
*/
void initialize_arguments(void);

/**
 * error_messages.c
 * Error messages to the stderr
*/
void malloc_error();
void check_terminal_args(int argc);
void file_error(void);

/**
 * get_stream.c
 * Stream file and read line by line
*/
void stream_file(char *file_path);

/**
 * tokenize.c
 * Tokenize each line from the stream
*/
void tokenize_line(void);

/**
 * instruction.c
 *
 * This gets instruction from the line and pass the
 * appropriate function to it and runs it accordingly
*/
void get_instruction(void);
void run_instruction(void);

/**
 * is_number.c
 * Checks if the value in the line is a number
 */
int is_number(char *str);

/**
 * free_arguments.c
 * Free arguments, stream and tokens
*/
void free_tokens(void);
void close_stream(void);
void free_arguments(void);

/**
 * free_all-arguments.c
 * Frees all args, tokens and struct
*/
void free_all_args(void);

/**
 * delete_node.c
 * Deletes a node after operation is execute
*/
void delete_node(void);

/*Operation Functions*/

/**
 * push_pall.c
 * Adding a node and printing all nodes
*/
void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);

/**
 * pop_pint_swap.c
 * Removes, prints the value of first node as a character
 * and also swap two nodes
*/
void pop(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);

/**
 * arithmetic.c
 * Adds, subtract, multiply, divide and modulate two values
*/
void add(stack_t **stack, unsigned int line_number);
void sub(stack_t **stack, unsigned int line_number);
void _div(stack_t **stack, unsigned int line_number);
void mul(stack_t **stack, unsigned int line_number);
void mod(stack_t **stack, unsigned int line_number);

/**
 * nop.c
 * Does nothing
*/
void nop(stack_t **stack, unsigned int line_number);

/**
 * pchar_pstr_rotl_rotr.c
 * These prints characters, string, and rotates nodes
*/
void pchar(stack_t **stack, unsigned int line_number);
void pstr(stack_t **stack, unsigned int line_number);
void rotl(stack_t **stack, unsigned int line_number);
void rotr(stack_t **stack, unsigned int line_number);

/**
 * stack_queue.c
 * Checks if instruction is stack or queue
*/
void stack(stack_t **stack, unsigned int line_number);
void queue(stack_t **stack, unsigned int line_number);

#endif /*MONTY_H*/
