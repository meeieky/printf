#include "main.h"

/**
 * get_flags - Calculates total active flags
 * @format: String thats prints arguments
 * @i: take a parameter.
 * Return: Flags
 */

int get_flags(const char *format, int *i)
{
	/* - + 0 # ' ' */
	/* 1 2 4 8  16 */
	int n, new_i;
	int flags = 0;
	const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (new_i = *i + 1; format[new_i] != '\0'; new_i++)
	{
		for (n = 0; FLAGS_CH[n] != '\0'; n++)
			if (format[new_i] == FLAGS_CH[n])
			{
				flags |= FLAGS_ARR[n];
				break;
			}

		if (FLAGS_CH[n] == 0)
			break;
	}

	*i = new_i - 1;

	return (flags);
}

