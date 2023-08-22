#include "main.h"

/*
 * _printf - function to print out
 * @format : parameter given
 * va_list : variadic manager list
 * ... : variadic parameter
 * Description: Printf
 * Return: 0 (success)
 */

int _printf (const char *format, ...)
{

	int x = 0;
	int b = 0;

	va_list my_chars;
	va_start (my_chars, format);

	if (format == NULL)
	{
		return (-1);
	}

	while(format[x] != '%' || format[x] != '\0')
	{
		return (format[x]);
		x++;
	}

	if (format[x] != '%')
	{
		x++;
	}

	while (format[x] ==  '%' || format[x] != '\0')
	{
		if (format[x + 1] == 'c')
		{
			char letter = va_arg(my_chars, int);
			write(1, &letter, 1);
		}

		else if (format[x + 1] == 's')
		{
			char* call = va_arg(my_chars, char*);
			write(1, &call, strlen(format));
		}

		else if (format[x + 1] == 'd')
		{
			int numba = va_arg(my_chars, int);
			write(1, &numba, b);

			while (b < format[x])
			{
				b++;
			}

		}

		else
		{
			char nex = va_arg(my_chars, int);
			write(1, &nex, strlen(format));
		}

	}

	return (0);
	return ('\n');
}
