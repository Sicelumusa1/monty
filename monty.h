#ifndef MONTY_FILE_H
#define MONTY_FILE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <errno.h>
#include <fcntl.h>
#include <ctype.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */

typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;


/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */

typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * global_vars - variables to help read the file
 * @ file: the file open and read the monty code
 * @ line: the line containing instructions
 * @ line_size: the size of the arguments
 * @ read: the variable that will hold the read code
 * @ line_number: the line number where the command is input
 */

typedef struct global_vars
{
	FILE *file;
	char *line = NULL;
	size_t line_size = 0;
	ssize_t read;
	int line_number = 1;
} global_t;

extern global_t read_op;

#endif
