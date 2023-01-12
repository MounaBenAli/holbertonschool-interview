#include "holberton.h"

int is_valid_number(char *num);
void multiply(int *num1, int *num2, int len1, int len2, int *result);
void reverse(int *num, int len);

int main(int argc, char *argv[])
{
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

int len1 = strlen(argv[1]);
int len2 = strlen(argv[2]);

int num1[len1], num2[len2], result[len1 + len2];
for (int i = 0; i < len1; i++)
{
num1[i] = argv[1][i] - '0';
}
for (int i = 0; i < len2; i++)
{
num2[i] = argv[2][i] - '0';
}

reverse(num1, len1);
reverse(num2, len2);

multiply(num1, num2, len1, len2, result);
reverse(result, len1 + len2);

for (int i = 0; i < len1 + len2; i++)
{
printf("%d", result[i]);
}
printf("\n");

return (0);
}

int is_valid_number(char *num)
{
int len = strlen(num);
for (int i = 0; i < len; i++)
{
if (!isdigit(num[i]))
{
return (0);
}
}
return (1);
}

void reverse(int *num, int len)
{
int temp;
for (int i = 0; i < len / 2; i++)
{
temp = num[i];
num[i] = num[len - i - 1];
num[len - i - 1] = temp;
}
}

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
