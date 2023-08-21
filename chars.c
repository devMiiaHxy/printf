#include "main.h"
#include <stdarg.h>


int _printf(const char *format, ...)
{
	int x = 0;
	va_list my_chars;
	va_start(my_chars, format);

	if (format == NULL)
	{
		int cal = va_arg (my_chars, int);
		write(-1, &cal, 0);
	}

	else
	{
		if (format[x] != '%')
		{
			write (1, format, strlen(format));
			x++;
		}

		 for (x = 0; format[x] != '\0'; x++)
		{

		if (format[x] == '%')
		{
			x++;

			if (format[x] == 'c')
			{
				char value = va_arg(my_chars, int);
				char line = '\n';
				write (1, &value, 1);
				write (1, &line, 1);
				
			}

			else if (format[x] == 's')
			{
				char lin = '\n';
				write (1, &lin, 1);

				while (format[x] != '\0')
				{
					char val = va_arg(my_chars, int);
					write (1, &val, strlen(format));
					x++;
				}
			}

			else
			{
				char val2 = '%';
				write (1, &val2, 1);
			}
		
		}

		}

	}

	va_end (my_chars);

	return (0);
}
