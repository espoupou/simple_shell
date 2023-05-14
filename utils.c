#include "main.h"

/**
 * _strcmp - compare two string
 * @s1: first string
 * @s2: the second string
 * Return: -1 0 or 1
 */

int _strcmp(char *s1, char *s2)
{
	char *p = s1, *q = s2;

	while (*p == *q && *p)
	{
		p++;
		q++;
	}

	if (*p > *q)
		return (1);
	if (*p < *q)
		return (-1);
	return (0);
}

/**
 * _strcpy - copie to dest src
 * @dest: destination
 * @src: source
 * Return: point to dest
 */

char *_strcpy(char *dest, char *src)
{

	size_t i;

	for (i = 0; src[i] != '\0'; i++)
	{
		dest[i] = src[i];
	}
	dest[i] = '\0';

	return (dest);
}
