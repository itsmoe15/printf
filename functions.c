#include "main.h"

/**
 * print_char - print char.
 * @c: the char
 *
 * Return: len.
 */

int print_char(char c)
{
	return (write(1, &c, 1));
}

/**
 * print_string - print string.
 * @s: the the string
 *
 * Return: len.
 */

int print_string(char *s)
{
	return (write(1, s, strlen(s)));
}

/**
 * print_number - print number
 * @n: number to be printed
 *
 */

void print_number(int n)
{
	unsigned int n1;

	if (n < 0)
	{
		n1 = -n;
		print_char('-');
	}
	else
		n1 = n;

	if (n1 / 10)
		print_number(n1 / 10);

	print_char((n1 % 10) + '0');
}

/**
 * num_length - return the number len
 * @n: number to be printed
 *
 * Return: len.
 */

int num_length(int n)
{
	int len = 1;

	if (n < 0)
		len++;
	while (n /= 10)
		len++;

	return (len);
}

/**
 * checker - print argument
 * @c: the checker
 * @args: the arguments
 *
 * Return: len.
 */

int checker(char c, va_list args)
{
	int num, len = 0;
	char *str;

	switch (c)
	{
		case 'c':
			len += print_char(va_arg(args, int));
			break;
		case 's':
			str = va_arg(args, char *);
			len += print_string(STRING);
			break;
		case 'd':
		case 'i':
			num = va_arg(args, int);
			print_number(num);
			len += num_length(num);
			break;
		case 'b':
			len += print_binary(va_arg(args, unsigned int));
			break;
		case '%':
			len += print_char('%');
			break;
		default:
			len += print_char('%');
			len += print_char(c);
			break;
	}
	return (len);
}
