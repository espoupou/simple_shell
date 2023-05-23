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

/**
 * _strncpy - copy n bit of src to dest
 * @dest: destination string
 * @src: source string
 * @n: the number of bit
 * Return: the dest string
 */

char *_strncpy(char *dest, char *src, int n)
{
	int i;

	for (i = 0; *(src + i) != '\0' && i < n; i++)
	{
		*(dest + i) = *(src + i);
	}

	while (i < n)
	{
		*(dest + i) = '\0';
		i++;
	}

	return (dest);
}

/**
 * _strcat - concatenate string
 * @dest: destinatio $n string
 * @src: source
 * Return: concatenated string
 */

char *_strcat(char *dest, char *src)
{
	int i, j;

	for (i = 0; dest[i] != '\0'; i++)
		;

	for (j = 0; src[j] != '\0'; j++, i++)
		dest[i] = src[j];

	dest[i] = '\0';
	return (dest);
}
