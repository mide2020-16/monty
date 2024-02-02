#include "monty.h"

/**
 * delete_node - Deletes a node after an operation is done
 */
void delete_node(void)
{
	stack_t *temp;

	temp = arguments->head;
	arguments->head = temp->next;
	free(temp);
}
