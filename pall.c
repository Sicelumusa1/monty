#include "monty.h"

/**
 * pall - print the elements of the stack
 * @stack: pointer to the stack
 * @line_number: line number in the file
 */

void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *curr = *stack;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pall, stack empty", line_number);
		exit(EXIT_FAILURE);
	}

	while (curr != NULL)
	{
		printf("%d\n", curr->n);
		curr = curr->next;
	}
}
