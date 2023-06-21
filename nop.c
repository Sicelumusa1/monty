#include "monty.h"

/**
 * nop - Does nothing.
 * @stack: pointer to pointer that has stack address
 * @line_number: line number where opcode is found
 */

void nop(stack_t **stack, unsigned int line_number)
{
	(void)line_number;
	(void)stack;
}
