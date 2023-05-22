#include "main.h"
#include <string.h>

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
	printf("%s\n", input);
	for (p = input; *p != '\n' && *p != '\0'; p++)
		printf("%c\n", *p);
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
	int loop = 1, size, i;
	char *input = NULL;
	char *token;

	while (loop)
	{
		write(STDIN_FILENO, ":)$ ", 4);

		/* size = get_cmd(&input); */
		size = _getline(datas);
		if (size == 0)
		{
			loop = 0;
			free(datas->input);
			continue;
		}

		input = _clean(datas->input);

/*		datas->input = input; */
		datas->args[0] = input;

		token = strtok(datas->input, " ");
		i = 0;

		while (token != NULL && i < 2)
		{
			datas->args[i] = token;
			token = strtok(NULL, " ");
			i++;
		}
		datas->args[i] = NULL;

		if (_strcmp("exit", datas->input) == 0)
		{
			free(input);
			loop = 0;
			break;
		}
		_exec(datas);
		free(input);
	}
}
