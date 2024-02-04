#include "monty.h"
#include "tasks/instruction.c"

<<<<<<< HEAD
=======
/**
 * invalid_instruction - Checks if the opcode in the line is invalid
 */
void invalid_instruction(void)
{
	char *opcode = arguments->instruction->opcode;
	
	fprintf(stderr, "L%d: unknown instruction %s\n", arguments->ln, opcode);
	free_all_args();
	exit(EXIT_FAILURE);
}

/**
 * get_instruction - Get the particular instruction of the current line
 * Return: void
 */
void get_instruction(void)
{
	int i = 0;

	instruction_t instructions[] = {
		{"push", &push}, {"pop", &pop}, {"pint", &pint}, {"swap", &swap}, {"nop", &nop}, {"pall", &pall}, {"add", &add}, {"sub", &sub}, {"div", &_div}, {"mul", &mul}, {"rotl", &rotl}, {"rotr", &rotr}, {"stack", &stack}, {"queue", &queue}, {"pstr", &pstr}, {"pchar", &pchar}, {"mod", &mod}, {NULL, NULL}};

	if (arguments->n_tokens == 0)
		return;

	if (arguments->tokens[0][0] == '#')
	{
		arguments->instruction->opcode = "nop";
		arguments->instruction->f = nop;
	}

	if (arguments->instruction != NULL && arguments->instruction->opcode != NULL)
	{
		while (instructions[i].opcode != NULL){
			if (strcmp(instructions[i].opcode, arguments->tokens[0]) == 0)
			{
				arguments->instruction->opcode = instructions[i].opcode;

				arguments->instruction->f = *instructions[i].f;
				return;
			}
			i++;
		}
	}

	invalid_instruction();
}

/**
 * run_instruction - Runs the instructioin with the appropriate
 * function
 * Return: void
 */
void run_instruction(void)
{
	stack_t *stack = NULL;

	if (arguments->n_tokens == 0)
		return;

	arguments->instruction->f(&stack, arguments->ln);
}
>>>>>>> refs/remotes/origin/main
