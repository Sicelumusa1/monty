#include "monty.h"

/**
 * is_whitespace - checks for white spaces in the bytecode file
 * @str: string to be searched for whitespaces
 * Return: True if a whitespace is encountered, false otherwise
 */

bool is_whitespace(const char *str)
{
	while (*str != '\0')
	{
		if (!isspace((unsigned char)*str))
		{
			return (false);
		}
		str++;
	}

	return (true);
}
