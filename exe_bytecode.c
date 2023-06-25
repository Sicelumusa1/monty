#include "monty.h"

/**
 * exe_bytecode - reads and processes bytecode instructions from a file
 * @line: pointer to the line read from bytecode file
 * @line_number: The number from which the line was read
 * @stack: stack on which the operation must be done
 */

void exe_bytecode(const char *line, int line_number, stack_t **stack)
{

	int i;
	char *opcode;
	char *line_copy;
	instruction_t *opcodes;

	line_copy = strdup(line);
	opcode = strtok(line_copy, " \t\r\n");
	if (opcode == NULL)
	{
		return;
	}

	/* remove non opcode/int argument if present */
	if (opcode[strlen(opcode) - 1] == '$')
	{
		opcode[strlen(opcode) - 1] = '\0';
	}

	/* extract the argument if present */
	read_op.push_argument = strtok(NULL, " \t\r\n");

	/*Process the opcode*/
	opcodes = get_opcodes();

	/* search for the opcode in the instructions array */
	for (i = 0; opcodes[i].opcode != NULL; i++)
	{
		if (strcmp(opcode, opcodes[i].opcode) == 0)
		{
		/* call the corresponding opcode handler */
			opcodes[i].f(stack, line_number);
			free(line_copy);
			return;
		}
	}
	/* if no match is found print error */
	fprintf(stderr, "Error: Unknown instruction %s at line %u\n",
			opcode, line_number);
	free(line_copy);
	exit(EXIT_FAILURE);
}
