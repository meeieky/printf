#include "main.h"

/**
 * get_size - Calculates the size
 * @format: String that prints arguments
 * @i: List of arguments to be printed.
 * Return: Precision
 */

int get_size(const char *format, int *i)
{
	int new_i = *i + 1;
	int size = 0;

	if (format[new_i] == 'l')
		size = S_LONG;
	else if (format[new_i] == 'h')
		size = S_SHORT;

	if (size == 0)
		*i = new_i - 1;
	else
		*i = new_i;

	return (size);
}

