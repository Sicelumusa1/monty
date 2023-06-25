#include "monty.h"

/**
 * mod - finds the remainder if second top element id divided by the
 * top element of the stack
 * @stack: pointer to the pointer that has the address of the stack
 * @line_number: Number of the line from which the opcode instruction is found
 */

void mod(stack_t **stack, unsigned int line_number)
{
	stack_t *top = *stack;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	if (top->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	top->next->n %= top->n;
	*stack = top->next;
	free(top);
}
