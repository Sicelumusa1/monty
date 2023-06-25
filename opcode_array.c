#include "monty.h"

/**
 * get_opcodes - get the opcode array
 * Return: The opcode array
 */

instruction_t *get_opcodes(void)
{
	static instruction_t instruction[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{"sub", sub},
		{"mul", mul},
		{"mod", mod},
		{NULL, NULL}
	};

	return (instruction);
}
