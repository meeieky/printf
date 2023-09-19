#include "main.h"

void print_buffer(char buffer[], int *buff_ind);

/**
 * _printf - It prints the functions
 * @format: format.
 * Return: Printed chars.
 */

int _printf(const char *format, ...)
{
	int q, print = 0, printed_chars = 0;
	int flags, width, precision, size, buff_ind = 0;
	va_list list;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(list, format);

	for (q = 0; format[q] != '\0'; q++)
	{
		if (format[q] != '%')
		{
			buffer[buff_ind++] = format[q];
			if (buff_ind == BUFF_SIZE)
				print_buffer(buffer, &buff_ind);
			/* write(1, &format[i], 1);*/
			printed_chars++;
		}
		else
		{
			print_buffer(buffer, &buff_ind);
			flags = get_flags(format, &q);
			width = get_width(format, &q, list);
			precision = get_precision(format, &q, list);
			size = get_size(format, &q);
			++q;
			print = handle_print(format, &q, list, buffer,
				flags, width, precision, size);
			if (print == -1)
				return (-1);
			printed_chars += print;
		}
	}

	print_buffer(buffer, &buff_ind);

	va_end(list);

	return (printed_chars);
}

/**
 * print_buffer - Prints contents of  buffer
 * @buffer: Array of chars
 * @buff_ind: Represents the length
 */
void print_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
		write(1, &buffer[0], *buff_ind);

	*buff_ind = 0;
}

