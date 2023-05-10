#include "main.h"

/**
 * get_cmd - get inputed command line
 * Return: the string inputed
 */

int get_cmd(char *input)
{
	size_t bufsize = 0;
	int size;

	size = getline(&input, &bufsize, stdin);

	return (size);
}

/**
 * shell_loop - the shell loop
 * Return: nothing
 */

void shell_loop()
{
	int loop = 1, size;
	char *input = NULL;

	while (loop)
	{
		write(STDIN_FILENO, ":)$ ", 4);
		size = get_cmd(input);

		if (size == 0)
		{
			loop = 0;
			free(input);
		}
		printf("%s", input);
	}
}
