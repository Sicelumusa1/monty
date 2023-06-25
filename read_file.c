#include "monty.h"

/**
 * process_bytecode_file - reads bytecode file line by line and carry out
 * the instruction contained
 * @filename: pointer/path to the file to be processed
 * @stack: stack on which to perform the operations
 * Return: True if the file is found and processed, false otherwise
 */

bool process_bytecode_file(const char *filename, stack_t **stack)
{
	char *line = NULL;
	size_t line_size = 0;
	ssize_t read;
	int line_number = 1;

	read_op.file = fopen(filename, "r");
	if (read_op.file == NULL)
	{
		fprintf(stderr, "Error: Unable to open file '%s'\n", filename);
		return (false);
	}

	while ((read = getline(&line, &line_size, read_op.file)) != -1)
	{
		line_number++;

		/* Remove trailing newline character, if present*/
		if (line[read - 1] == '\n')
		{
			line[read - 1] = '\0';
			read--;
		}

		/* check if the line is empty or contains only whitespaces */
		if (read == 0 || is_whitespace(line))
		{
			continue;
		}

		/* Parse the line and execute the opcode */
		exe_bytecode(line, line_number, stack);
	}

	free(line);
	fclose(read_op.file);

	return (true);
}
