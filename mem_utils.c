#include "main.h"

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
