#include "main.h"

/**
 * _clean - clean inputed command line
 * @input: inputed line
 * Return: cleaned string
 */

char *_clean(char *input)
{
	char *p;

	/* remove beginning spaces */
	for (p = input; *p == ' '; p++)
		;
	if (p != input)
	{
		_memcpy(input, p, _strlen(p) + 1);
/*		_mem_skipn_cpy(input, p, p - input - 1);*/
	}

	/* go to end */
	for (p = input; *p != '\n' && *p != '\0'; p++)
		;

	/* remove ending spaces */
	while ((p != input) && (*(p - 1) == ' '))
		p--;

	if (p == input)
		return (NULL);
	*p = '\0';
/*printf("%s-\n", input);*/
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

	free_args(datas);
	datas->args = malloc(sizeof(char *)); /* end array value space : NULL space */
/*printf("%s\n", input);*/
	datas->args[0] = input;

	arg_start = input;
	i = 0;
	while (*arg_start != '\0')
	{
		arg_start += _strspn(arg_start, " \t");
		arg_end = _strchr(arg_start, ' ');

		if (arg_end == NULL)
			arg_end = arg_start + _strlen(arg_start);

		datas->args = realloc_da(datas->args, (i + 1), (i + 2));
		if (datas->args == NULL)
			return (0);

		datas->args[i] = malloc(sizeof(char) * (arg_end - arg_start) + 1);
		_memcpy(datas->args[i], arg_start, arg_end - arg_start);

		datas->args[i][arg_end - arg_start] = '\0';
		arg_start = arg_end + _strspn(arg_end, " \t");
		i++;
	}

	datas->args[i] = NULL;

	return (1);
}

/**
 * free_args - free args
 * @datas: datas
 * Return: nothing
 */

void free_args(data *datas)
{
	int i;

	if (!datas->args)
		return;

	for (i = 0; datas->args[i]; i++)
		free(datas->args[i]);
	free(datas->args);
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
	/*		if (datas->input);
				free(datas->input); */
			continue;
		}
		input = _clean(datas->input);
		if (!input || _strlen(input) == 0)
		{
			free(datas->input);
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
		datas->counter += 1;
		free(input);
	}
}
