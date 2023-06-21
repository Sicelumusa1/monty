#include "monty.h"

int main(argc, argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}

	read_op.file = fopen(argv[1], "r")
	
	if (read_op.file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1])
		return (EXIT_FAILURE);
	}

	/*Read and process the file line by line*/
	while((read_op.read = getline(&read_op.line, &read_op.line_size, read_op.file)) != -1)
	{
		/*functions to call to read line by line and execute*/
		line_number++;
	}

	/*Check if there was an error while reading the file*/
	if (ferror(read_op.file))
	{
        	fprintf(stderr, "Error: Failed to read the file %d\n", argv[1]);
		fclose(read_op.file);
		free(read_op.line);
		return (EXIT_FAILURE);
	}

	fclose(read_op.file);
	free(read_op.line);
	return (EXIT_SUCCESS);
}
