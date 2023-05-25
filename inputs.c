#include "main.h"

/**
 * _getline - get inputed line
 * @datas: datas
 * Return: the size
 */

int _getline(data *datas)
{
	char c = '\0', *q;
	int i = 0;
	ssize_t size;

	datas->input = malloc(sizeof(char) * 256);
	if (datas->input == NULL)
		return (0);

	while (c != '\n' && c != EOF)
	{
		size = read(STDIN_FILENO, &c, 1);
		if (size == 0)
		{
	/*		_putchar('\n'); */
			return (0);
		}

		if (i > 255)
		{
			/* realloc space */
			q = malloc(sizeof(char) * (i + 1)); /* the new char and \0 */
			if (q == NULL)
				return (0);

			q = _strncpy(q, datas->input, i);
			free(datas->input);

			datas->input = q;
		}

		*(datas->input + i) = c;
		i++;
	}
	*(datas->input + i) = '\0';

	return (i + 1);
}
