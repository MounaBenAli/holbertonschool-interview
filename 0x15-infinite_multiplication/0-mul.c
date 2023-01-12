#include "holberton.h"




/**
 * is_valid_number - check if the given string is a valid number
 * @num: string to check
 *
 * Return: 1 if valid, 0 otherwise
 */
int is_valid_number(char *num)
{
	int len = strlen(num);
	int i;

	for (i = 0; i < len; i++)
	{
		if (!isdigit(num[i]))
		{
			return (0);
		}
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
	int i, j, carry, temp;

	for (i = 0; i < len1 + len2; i++)
	{
		result[i] = 0;
	}

	for (i = 0; i < len1; i++)
	{
		carry = 0;
		for (j = 0; j < len2; j++)
		{
			temp = result[i + j] + num1[i] * num2[j] + carry;
			result[i + j] = temp % 10;
			carry = temp / 10;
		}

	result[i + len2] += carry;
	}
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
    int num1[len1], num2[len2], result[len1 + len2];
    int i;

	if (argc != 3)
	{
		printf("Error\n");
		exit(98);
	}

	if (!is_valid_number(argv[1]) || !is_valid_number(argv[2]))
	{
		printf("Error\n");
		exit(98);
	}

	


	for (i = 0; i < len1; i++)
	{
		num1[i] = argv[1][i] - '0';
	}

	for (i = 0; i < len2; i++)
	{
		num2[i] = argv[2][i] - '0';
	}

	reverse(num1, len1);
	reverse(num2, len2);

	multiply(num1, num2, len1, len2, result);
	reverse(result, len1 + len2);

	for (i = 0; i < (len1 + len2); i++)
	{
		_putchar(result[i] + '0');
	}
	_putchar('\n');
return (0);
}
