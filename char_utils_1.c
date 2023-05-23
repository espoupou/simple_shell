#include "main.h"

/**
 * _strdup - duplicate string
 * @s: the string
 * Return: the new string
 */

char *_strdup(char *s)
{
	char *n;
	size_t len;

	len = _strlen(s);
	n = malloc(sizeof(char) * (len + 1));
	if (n == NULL)
		return (NULL);
	memcpy(n, s, len + 1);
	return (n);
}
