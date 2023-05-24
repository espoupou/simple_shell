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

	for (p = input; *p != '\n' && *p != '\0'; p++)
		;

	if (p == input)
		return (NULL);
	*p = '\0';

	return (input);
}

/**
 * parse_args - parses user input and handles command line arguments
 * @input: contains line to be parsed
 * @datas: datas
 * Return: status 0 or 1
 */

int parse_args(char *input, data *datas)
{
	int i;
	char *arg_start, *arg_end;

	datas->input = input;
	datas->args = malloc(sizeof(char *)); /* end array value space : NULL space */
	datas->args[0] = input;

	arg_start = input;
	i = 0;
	while (*arg_start != '\0')
	{
		arg_start += strspn(arg_start, " \t");
		arg_end = strchr(arg_start, ' ');

		if (arg_end == NULL)
			arg_end = arg_start + strlen(arg_start);

		datas->args = realloc_da(datas->args, (i + 1), (i + 2));
		if (datas->args == NULL)
			return (0);

		datas->args[i] = malloc(sizeof(char) * (arg_end - arg_start));
		memcpy(datas->args[i], arg_start, arg_end - arg_start);

		datas->args[i][arg_end - arg_start] = '\0';
		arg_start = arg_end + strspn(arg_end, " \t");
		i++;
	}

	datas->args[i] = NULL;

	return (1);
}

/**
 * shell_loop - the shell loop
 * @datas: datas
 * Return: nothing
 */

void shell_loop(data *datas)
{
	int loop = 1, size; /* , i; */
	int (*f)(data *datas);
	char *input = NULL;
/*	char *token; */

	while (loop)
	{
		write(STDIN_FILENO, ":)$ ", 4);
		size = _getline(datas);

		if (size == 0)
		{
			loop = 0;
			free(datas->input);
			continue;
		}
		input = _clean(datas->input);
		if (!input)
		{
			free(input);
			continue;
		}
		loop = parse_args(input, datas);
		if (loop == 0)
		{
			free(input);
			continue;
		}
		f = builtin_handler(datas->args[0]);
		if (f)
			loop = f(datas);
		else
			loop = _exec(datas);
		free(input);
	}
}
