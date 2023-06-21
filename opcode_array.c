#include "monty.h"

/**
 * get_opcodes - get the opcode array
 * Return: The opcode array
 */

instruction_t *get_opcodes(void)
{
	instruction_t instruction[] = {{"push", push},
		{"pall", pall}, {"pint", pint}, {NULL, NULL}};

	return (instruction);
}
