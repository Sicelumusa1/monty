#ifndef MONTY_H
#define MONTY_H
#define _GNU_SOURCE
#define MAX_BYTECODE_SIZE 1000

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
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
 * @ instruction: Array of opcode string and opcode handler
 * @ push_argument: contains the argument for push operation
 */

typedef struct global_vars
{
	FILE *file;
	char *line;
	size_t line_size;
	ssize_t read;
	int line_number;
	instruction_t *instruction;
	char *push_argument;
} global_t;

extern global_t read_op;

void exe_bytecode(const char *line, int line_number, stack_t **stack);
bool process_bytecode_file(const char *filename, stack_t **stack);
bool is_int(const char *str);
bool is_whitespace(const char *str);
instruction_t *get_opcodes(void);
void free_stack(stack_t *stack);
void swap(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);
void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);
#endif /*MONTY_H*/
