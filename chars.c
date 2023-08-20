#include "main.h"


int _printf(const char *format, ...)
{
	int x = 0;
	va_list my_chars;
	va_start (my_chars, format);

	if (format == NULL)
	{
		return (-1);
	}

	else
	{

		if (format[x] != '\0' && format[x] != '%')
		{
			x++;
			write (1, format, strlen(format));
		}

		if (format[x] != '\0' && format[x] == '%')
		{
			if (format[x + 1] == 'c')
			{
				int value = va_arg (my_chars, int);
				write (1, &value, 1);
			}

			else if (format[x + 1] == 's')
			{
				int val = va_arg (my_chars, int);

				while (format[x + 1] != '\0')
				{
					write (1, &val, strlen(format));
					x++;
				}
			}

			else
			{
				int val2 = va_arg (my_chars, int);
				write (1, &val2, 1);
			}
		}
	}

	va_end (my_chars);

	return (0);
}
