#include "monty.h"

/**
 * pop - remove the top element from the stack
 * @stack: pointer to the stack
 * @line_number: Line number in the file
 */

void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *top = *stack;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	*stack = top->next;

	if (*stack != NULL)
		(*stack)->prev = NULL;

	free(top);
}
