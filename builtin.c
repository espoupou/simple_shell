#include "main.h"

/**
 * builtin_handler - choose builtin function
 * @input: inputed line
 * Return: status 0 or 1
 */

int (*builtin_handler(char *input))(data * datas)
{
	builtin builtins[] = {
		{"exit", __exit},
		{"env", __env},
		{"setenv", __setenv},
		{"unsetenv", __unsetenv},
		{"cd", __cd},
		{NULL, NULL}
		};
	int i;

	for (i = 0; builtins[i].name != NULL; i++)
	{
		if (_strcmp(builtins[i].name, input) == 0)
			break;
	}
	return (builtins[i].f);
}

/**
 * __exit - exit the program
 * @datas: datas
 * Return: always 0
 */

int __exit(data *datas)
{
	unsigned int ustatus;
	int big_number;

	if (datas->args[1] != NULL)
	{
		ustatus = _atoi(datas->args[1]);
		big_number = ustatus > (unsigned int)INT_MAX;
		if (!_isdigit(datas->args[1]) || _strlen(datas->args[1]) > 10 || big_number)
		{
			get_error(datas, 2);
			datas->status = 2;
			return (1);
		}
		datas->status = (ustatus % 256);
	}
	return (0);
}

/**
 * __env - print environment
 * @datas: datas
 * Return: always 1
 */

int __env(data *datas)
{
	int i, len;

	for (i = 0; datas->environ[i]; i++)
	{

		for (len = 0; datas->environ[i][len]; len++)
			;

		write(STDOUT_FILENO, datas->environ[i], _strlen(datas->environ[i]));
		write(STDOUT_FILENO, "\n", 1);
	}
	datas->status = 0;
	return (1);
}
