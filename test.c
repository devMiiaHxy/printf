#include "main.h"

/*
 * _printf - function to print out
 * @format : parameter given
 * @... : variadic parameter
 * write : alias to printf
 * Description: Printf
 * Return: 0 (success)
 */

int _printf (const char *format, ...)
{
	unsigned int x;
 	unsigned int track = 0;

	va_list my_chars;
	va_start (my_chars, format);

	for (x = 0; format[x] != '\0'; x++)
	{
		if (format[x] != '%')
		{
			sout(format[x]);
		}

		if (format[x] == '%' && format[x + 1] == 'c')
		{
			sout(va_arg(my_chars, int));
			x++;
		}

		track++;
	}

	return (track);

}
