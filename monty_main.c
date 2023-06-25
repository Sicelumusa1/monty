#include "monty.h"

global_t read_op;

/**
 * main - entry point for the program
 * @argc: number of arguments
 * @argv: argument vector
 * Return: 0
 */

int main(int argc, char *argv[])
{
	stack_t *stack = NULL;

	/* Check if the bytecode file is provided as a command-line argument */
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}

	read_op.push_argument = NULL;
	/* Read and process the bytecode instructions */
	if (!process_bytecode_file(argv[1], &stack))
	{
		free_stack(stack);
		return (EXIT_FAILURE);
	}

	free_stack(stack);

	return (EXIT_SUCCESS);
}
