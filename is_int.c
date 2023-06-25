#include "monty.h"

/**
 * is_int - checks if a given string is integer or not
 * @str: pointer to string to check
 * Return: true if it is integer, false if not
 */

bool is_int(const char *str)
{
	if (*str == '-' || *str == '+')
		++str;

	if (*str == '\0')
		return (false);

	while (*str != '\0')
	{
		if (*str < '0' || *str > '9')
			return (false);
		++str;
	}

	return (true);
}
