#include "main.h"

/**
 * sout - give output to stdoutput
 * @c: input parameter
 *
 * Return: bytes amount
 */

int sout(char c)
{
	return (write(1, &c, 1));
}

