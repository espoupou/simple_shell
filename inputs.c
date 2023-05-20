#include "main.h"

/**
 * _getline - get inputed line
 * @input: the input pointer
 * Return: the size
 */

int _getline(char *input)
{
	char c = '\0', *q;
	int i = 0;
	ssize_t size;
write(STDOUT_FILENO, " - tch \n", 8);
	input = malloc(sizeof(char) * 256);
write(STDOUT_FILENO, " - tch checking if NULL ...\n", 8);
	if (input == NULL)
		return (0);
write(STDOUT_FILENO, " - tch input not NULL \n", 8);
	while (c != '\n' && c != EOF)
	{
write(STDOUT_FILENO, " - tch \n", 8);
		size = read(STDIN_FILENO, &c, 1);
		if (size == 0)
		{
			_putchar('\n');
			return (0);
		}

		if (i > 255)
		{
			/* realloc */
			q = malloc(sizeof(char) * (i + 1)); /* the new char and \0 */
			if (q == NULL)
				return (0);

			q = _strncpy(q, input, i);
			free(input);

			input = q;
		}
		input[i] = c;
		i++;
	}
	input[i] = '\0';

	return (i + 1);
}
