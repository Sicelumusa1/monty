#include "monty.h"

/**
 * get_opcodes - get the opcode array
 * Return: The opcode array
 */

instruction_t *get_opcodes(void)
{
	instruction_t *instruction = malloc(sizeof(instruction_t) * 7);

	if (instruction == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	instruction[0].opcode = "push";
	instruction[0].f = push;
	instruction[1].opcode = "pall";
	instruction[1].f = pall;
	instruction[2].opcode = "pint";
	instruction[2].f = pint;
	instruction[3].opcode = "pop";
	instruction[3].f = pop;
	instruction[4].opcode = "swap";
	instruction[4].f = swap;
	instruction[5].opcode = "add";
	instruction[5].f = add;
	instruction[6].opcode = NULL;
	instruction[6].f = NULL;

	return (instruction);
}
