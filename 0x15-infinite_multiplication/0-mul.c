#include "holberton.h"

/**
 * is_valid_number - check if the given string is a valid number
 * @num: string to check
 *
 * Return: 1 if valid, 0 otherwise
 */
int is_valid_number(char *num)
{
	int i = 0;

	while (num[i])
	{
	if (num[i] < '0' || num[i] > '9')
		return (0);
	i++;
	}
return (1);
}

/**
 * reverse - reverse the order of the digits in an array
 * @num: array to reverse
 * @len: length of the array
 */
void reverse(int *num, int len)
{
	int temp;
	int i;

	for (i = 0; i < len / 2; i++)
	{
		temp = num[i];
		num[i] = num[len - i - 1];
		num[len - i - 1] = temp;
	}
}

/**
 * multiply - multiply two large integers represented as arrays
 * @num1: first number
 * @num2: second number
 * @len1: length of the first number
 * @len2: length of the second number
 * @result: array to store the result
 */
void multiply(int *num1, int *num2, int len1, int len2, int *result)
{
	int index1, index2;

	for (index1 = 0; index1 < len1; index1++)
	{
		for (index2 = 0; index2 < len2; index2++)
		{
		result[index1 + index2] += num1[index1] * num2[index2];
		result[index1 + index2 + 1] += result[index1 + index2] / 10;
		result[index1 + index2] %= 10;
		}
	}
}

/**
 * exit_error - error return
 *
 * @status: error code to exit with
 */
void exit_error(int status)
{
	_putchar('E');
	_putchar('r');
	_putchar('r');
	_putchar('o');
	_putchar('r');
	_putchar('\n');
	exit(status);
}

/**
* main - entry point of the program
* @argc: number of arguments passed to the program
* @argv: array of arguments passed to the program
*
* Return: 0 on success, 98 on error
*/

int main(int argc, char *argv[])
{

	int len1 = strlen(argv[1]);
	int len2 = strlen(argv[2]);
	int *num1 = malloc(len1 * sizeof(int));
	int *num2 = malloc(len2 * sizeof(int));
	int *result = malloc((len1 + len2) * sizeof(int));
	int i;

	if (argc != 3)
	{
		exit_error(98);
	}

	if (!is_valid_number(argv[1]) || !is_valid_number(argv[2]))
	{
		exit_error(98);
	}

	for (i = 0; i < len1; i++)
	num1[i] = argv[1][len1 - i - 1] - '0';

	for (i = 0; i < len2; i++)
	num2[i] = argv[2][len2 - i - 1] - '0';

	multiply(num1, num2, len1, len2, result);
	i = len1 + len2 - 1;
	while (i >= 0 && result[i] == 0)
	i--;
	if (i == -1)
	_putchar('0');
	else
	while (i >= 0)
	_putchar(result[i--] + '0');
	_putchar('\n');
	free(num1);
	free(num2);
	free(result);
	return (0);
}
