#include "monty.h"

/**
 * push - Insert a new value into the stack
 * @stack: Pointer to the stack
 * @line_number: Line number in the file
 */

void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node;
	int value;
	char *argument = read_op.push_argument;

	if (argument == NULL)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	if (!is_int(argument))
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	value = atoi(argument);

	new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
	{
		fprintf(stderr, "Memory allocation failed\n");
		free(new_node);
		exit(EXIT_FAILURE);
	}

	new_node->n = value;
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack != NULL)
		(*stack)->prev = new_node;

	*stack = new_node;
}
