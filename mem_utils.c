#include "main.h"

/**
 * realloc_a - realloc for char array
 * @p: pointer to array
 * @old_size: old size
 * @new_size: new size
 * Return: pointer to allocatedd space
 */

char *realloc_a(char *p, int old_size, int new_size)
{
	char *n;

	if (!p)
	{
		n = malloc(sizeof(char) * new_size);
		_memset(n, '\0', new_size);
		return (n);
	}

	if (new_size == 0)
	{
		free(p);
		return (NULL);
	}

	if (old_size == new_size)
		return (p);

	n = malloc(sizeof(char) * new_size);
	if (n == NULL)
		return (NULL);

	if (new_size < old_size)
		_memcpy(n, p, new_size);
	else
		_memcpy(n, p, old_size);
	free(p);

	return (n);
}

/**
 * realloc_da - relloc for char double dim array
 * @p: pointer to array
 * @old_size: old size
 * @new_size: new size
 * Return: pointer to allocated space
 */

char **realloc_da(char **p, int old_size, int new_size)
{
	char **n;
	int i;

	if (p == NULL)
		return (malloc(sizeof(char *) * new_size));

	if (new_size == old_size)
		return (p);

	n = malloc(sizeof(char *) * new_size);
	if (n == NULL)
		return (NULL);

	for (i = 0; i < old_size; i++)
		n[i] = p[i];

	free(p);
	return (n);
}

/**
 * _memcpy - fills memory with a constant byte
 * @dest: destination memory aeria pointer
 * @src: source memory aeria pointer
 * @n: number of byte
 * Return: pointer to dest
 */

char *_memcpy(char *dest, const char *src, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
	{
		dest[i] = *(src + i);
	}

	return (dest);
}

/**
 * _memset - fills memory with a constant byte
 * @s: memory aeria
 * @b: the byte
 * @n: number of byte
 * Return: s adress
 */

char *_memset(char *s, char b, unsigned int n)
{
	char *p;

	for (p = s; p - s < n; p++)
	{
		*p = b;
	}

	return (s);
}

/**
 * _mem_skipn_cpy - copy src to dest but skip n first byte
 * @dest: destination memory aeria pointer
 * @src: source memory aeria pointer
 * @n: number of byte
 * Return: pointer to dest
 */

char *_mem_skipn_cpy(char *dest, const char *src, unsigned int n)
{
	unsigned int i;

        for (i = 0; src[i + n]; i++)
        {
                dest[i] = *(src + i);
        }

	dest[i] = '\0';
        return (dest);
}
