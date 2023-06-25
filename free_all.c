#include "monty.h"

/**
 * free_stack - Frees the memory that was allocated for the stack
 * @stack: stack in question
 */

void free_stack(stack_t *stack)
{
	stack_t *current = stack;
	stack_t *next;

	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
}
