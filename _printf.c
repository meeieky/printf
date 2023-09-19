#include "main.h"

void print_buffer(char buffer[], int *buff_ind);

/**
 * _printf - produces output according to a format
 * @format: format.
 * Return: Printed chars.
 */

int _printf(const char *format, ...)
{
	int i;
	char *st;
	char c;
	int count = 0;
	va_list list;

	if (format == NULL)
		return (-1);

	va_start(list, format);

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == '\0')
				break;
		}
		else if (format[i] == 'c')
		{
			c = va_arg(list, int);
			_putchar(c);
			count++;
		}
		else if (format[i] == 's')
		{
			st = va_arg(list, char *);
			while (*st)
			{
				_putchar(*st);
				st++;
				count++;
			}
		}
		else if (format[i] == '%')
		{
			_putchar('%');
			count++;
		}
		else
		{
			_putchar(format[i]);
			count++;
		}
	}

	va_end(list);

	return (count);
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

