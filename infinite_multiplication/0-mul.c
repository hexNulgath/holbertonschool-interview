#include "holberton.h"
#include <stdio.h>
#include <stdlib.h>


/**
 * multiply - Multiplies two positive integers as strings
 * @num1: First number as string
 * @num2: Second number as string
 *
 * Return: Result as newly allocated string
 */
char *multiply(const char *num1, const char *num2)
{
	int len1, len2, result_len;
	int i, j, carry, product, n1, n2, k, leading_zero;
	int *result_arr;
	char *result_str;

	len1 = _strlen(num1);
	len2 = _strlen(num2);
	result_len = len1 + len2;
	result_arr = malloc(result_len * sizeof(int));
	if (!result_arr)
		return (NULL);

	for (i = 0; i < result_len; i++)
		result_arr[i] = 0;

	for (i = len1 - 1; i >= 0; i--)
	{
		carry = 0;
		n1 = num1[i] - '0';
		for (j = len2 - 1; j >= 0; j--)
		{
			n2 = num2[j] - '0';
			product = n1 * n2 + result_arr[i + j + 1] + carry;
			carry = product / 10;
			result_arr[i + j + 1] = product % 10;
		}
		result_arr[i] += carry;
	}

	result_str = malloc(result_len + 1);
	if (!result_str)
	{
		free(result_arr);
		return (NULL);
	}

	k = 0;
	leading_zero = 1;
	for (i = 0; i < result_len; i++)
	{
		if (leading_zero && result_arr[i] == 0)
			continue;
		leading_zero = 0;
		result_str[k++] = result_arr[i] + '0';
	}
	if (k == 0)
		result_str[k++] = '0';
	result_str[k] = '\0';
	free(result_arr);
	return (result_str);
}


/**
 * main - Entry point
 * @argc: Argument count
 * @argv: Argument vector
 *
 * Return: 0 on success, 98 on error
 */
int main(int argc, char *argv[])
{
	   char *result;

	   if (argc != 3)
		   printE();

	   if (!is_number(argv[1]) || !is_number(argv[2]))
		   printE();

	   result = multiply(argv[1], argv[2]);
	   if (!result)
		   printE();

	   _puts(result);
	   _putchar('\n');
	   free(result);
	   return (0);
}


/**
 * _puts - Writes a string to stdout
 * @str: String to write
 *
 * Return: void
 */
void _puts(const char *str)
{
	   int i = 0;

	   while (str && str[i])
	   {
		   _putchar(str[i]);
		   i++;
	   }
}


/**
 * printE - Prints error message and exits with status 98
 *
 * Return: void
 */
void printE(void)
{
	_putchar('E');
	_putchar('r');
	_putchar('r');
	_putchar('o');
	_putchar('r');
	_putchar('\n');
	exit(98);
}


/**
 * is_number - Checks if a string contains only digits
 * @s: The string to check
 *
 * Return: 1 if only digits, 0 otherwise
 */
int is_number(char *s)
{
	   while (*s)
	   {
		   if (*s < '0' || *s > '9')
			   return (0);
		   s++;
	   }
	   return (1);
}


/**
 * _strlen - Calculates the length of a string
 * @str: The string to measure
 *
 * Return: Length of the string
 */
int _strlen(const char *str)
{
	   int len = 0;

	   while (str && str[len])
		   len++;
	   return (len);
}
