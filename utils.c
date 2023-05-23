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

/**
 * _putchar - write character
 * @c: the character
 * Return: 1
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _strncpy - copy n bit of src to dest
 * @dest: destination string
 * @src: source string
 * @n: the number of bit
 * Return: the dest string
 */

/**
 * cat_keyenv - create env string "key=val"
 * @env: env var pointer
 * @key: key
 * @val: value
 * Return: pointer to string
 */

char *cat_keyval(char *key, char *val)
{
	char *env;

	env = malloc(sizeof(char) * (_strlen(key) + _strlen(val) + 2));
	_strcpy(env, key);
	_strcat(env, "=");
	_strcat(env, val);
	_strcat(env, "\0");

	return (env);
}

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
