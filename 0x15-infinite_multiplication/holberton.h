#ifndef HOLBERTON_H_
#define HOLBERTON_H_

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

int _putchar(char c);
void reverse(int *result, int len);
int is_valid_number(char *numb);
void multiply(int *num1, int *num2, int len1, int len2, int *result);
void exit_error(int status);


#endif /* HOLBERTON_H_*/