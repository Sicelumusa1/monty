#include "monty.h"

/**
 * exe_bytecode - reads and processes bytecode instructions from a file
 * @bytecode: array of strings representing the bytecode instructions
 * @num_instructions: Number of instructions in the array
 */

void exe_bytecode(char **bytecode, int num_instructions)
{

	char *opcode;
	char *trimmed_opcode;
	int found = 0;
	int i, j;

	stack_t *stack = malloc(sizeof(stack_t));

	if (stack == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	for (i = 0; i < num_instructions; i++)
	{
		read_op.line = bytecode[i];

		opcode = strtok(read_op.line, " \t");
		if (opcode == NULL)
		{
			/* ignore empty lines */
			continue;
		}

		/* Remove leading spaces from the opcode */
		trimmed_opcode = opcode;
		while (*trimmed_opcode == ' ')
		{
			trimmed_opcode++;
		}

		/* search for the opcode in the instructions array */
		for (j = 0; read_op.instruction[j].opcode != NULL; j++)
		{
			if (strcmp(trimmed_opcode, read_op.instruction[i].opcode) == 0)
			{
			/* call the corresponding opcode handler */
			read_op.instruction[j].f(&stack, read_op.line_number);
				found = 1;
				break;
			}
		}

		if (!found)
		{
			/* if no match is found print error */
			fprintf(stderr, "Error: Unknown instruction %s at line %u\n",
					trimmed_opcode, read_op.line_number);
			exit(EXIT_FAILURE);
		}

		read_op.line_number++;
	}

	free(stack);
}
