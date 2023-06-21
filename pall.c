#include "monty.h"

/**
 * pall - print the elements of the stack
 * @stack: pointer to the stack
 * @line_number: line number in the file
 */

void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *curr = *stack;
	(void) line_number;

	if (curr == NULL)
		return;

	/*traverse the list untill NULL*/
	do {
		printf("%d\n", curr->n);
		curr = curr->next;
	} while (curr != NULL);
}
