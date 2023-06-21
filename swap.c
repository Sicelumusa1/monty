#include "monty.h"

/**
 * swap - swaps the top two elements of the stack
 * @stack: pointer to the pointer with address to the stack
 * @line_number: Line number where opcode is found
 */

void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *top = *stack;
	int temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = top->n;
	top->n = top->next->n;
	top->next->n = temp;
}
