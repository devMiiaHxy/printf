#include "main.h"


int _printf(const char *format, ...)
{

	if (format == NULL)
		return (-1);

	else
	{
		int x = 0;
		int i = 0;
		va_list my_chars;
		va_start (my_chars, format);

	while (format[x] != '\0')
	{
		if (format[x] != '%')
		{
			write(1, format, strlen(format));
			x++;
		}

		while (format[i] == '%')
		{
			if (format[i + 1] == 'c')
			{
				int value = va_arg (my_chars, int);
				write (1, &value, 1);
			}

			else if (format[i + 1] == 's')
			{
				while (format[i + 1] != '\0')
				{

					int val =  va_arg (my_chars, int);
					write (1, &val, strlen(format));
					i++;
				}
			}

			else
			{
				int val2 = va_arg (my_chars, int);
				write (1, &val2, 1);
			}

			i++;
		}


		x++;
	}

		va_end (my_chars);

	}

	return (0);
}
