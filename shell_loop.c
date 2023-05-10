#include "main.h"

/**
 * get_cmd - get inputed command line
 * @input: buffer for the inputed line
 * Return: the string inputed
 */

int get_cmd(char **input)
{
	size_t bufsize = 0;
	int size;

	size = getline(input, &bufsize, stdin);

	return (size);
}

/**
 * _clean - clean inputed command line
 * @input: inputed line
 * Return: cleaned string
 */

char *_clean(char *input)
{
	char *p;

	for (p = input; *p != '\n'; p++)
		;
	*p = '\0';
	return (input);
}

/**
 * shell_loop - the shell loop
 * @datas: datas
 * Return: nothing
 */

void shell_loop(data *datas)
{
	int loop = 1, size;
	char *input = NULL;

	while (loop)
	{
		write(STDIN_FILENO, ":)$ ", 4);
		size = get_cmd(&input);

		if (size == 0)
		{
			loop = 0;
			free(input);
			continue;
		}
		input = _clean(input);

		datas->input = input;
		datas->args[0] = input;
		datas->args[1] = NULL;

		_exec(datas);
		free(input);
	}
}
