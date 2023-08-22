#include "main.h"

/**
 * _printf - function to print out
 * @format: parameter given
 * @...: variadic parameter
 *
 * Return: 0 (success)
 */

int _printf(const char *format, ...)
{
	unsigned int x , j;
	unsigned int track = 0, str_track = 0;

	va_list my_chars;

	if (!format && format == NULL)
		return (-1);

	va_start(my_chars, format);

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
		if (format[x] == '%' && format[x + 1] == 's')
		{
			str_track = str_out(va_arg(my_chars, char *));
			x++;
			for (j = 1; j < str_track; j++)
				j += track;
		}
		if (format[x] == '%' && format[x + 1] == '%')
		{
			sout('%');
		}
		track++;
	}
	va_end(my_chars);
	return (track);
}
