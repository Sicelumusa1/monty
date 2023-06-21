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
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}

	read_op.file = fopen(argv[1], "r");

	if (read_op.file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		return (EXIT_FAILURE);
	}

	read_op.line = NULL;
	read_op.line_size = 0;
	read_op.line_number = 1;
	read_op.num_instructions = 0;
	read_op.instruction = NULL;

	/*Read and process the file line by line*/
	while ((read_op.read = getline(&read_op.line, &read_op.line_size,
					read_op.file)) != -1)
	{
		/* call exe_bytecode and pass the line as the parameter */
		exe_bytecode(&read_op.line, read_op.num_instructions);
		read_op.line_number++;
	}

	/*Check if there was an error while reading the file*/
	if (ferror(read_op.file))
	{
		fprintf(stderr, "Error: Failed to read the file %s\n", argv[1]);
		fclose(read_op.file);
		free(read_op.line);
		return (EXIT_FAILURE);
	}

	fclose(read_op.file);
	free(read_op.line);
	free(read_op.instruction);
	return (EXIT_SUCCESS);
}
