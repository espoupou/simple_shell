#include "main.h"

/**
 * _strlen - length of string
 * @s: the string
 * Return: the length
 */

int _strlen(char *s)
{
	int len;

	for (len = 0; s && s[len]; len++)
		;
	return (len);
}
