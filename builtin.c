#include "main.h"

/**
 * builtin_handler - choose builtin function
 * @input: inputed line
 * Return: status 0 or 1
 */

int (*builtin_handler(char *input))(data *datas)
{
	builtin builtins[] = {
		{"exit", __exit},
		{"env", __env},
		{"setenv", __setenv},
		{"unsetenv", __unsetenv},
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
	UNUSED(datas);
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

/*	UNUSED(datas); */
	for (i = 0; datas->environ[i]; i++)
	{

		for (len = 0; datas->environ[i][len]; len++)
			;

		write(STDOUT_FILENO, datas->environ[i], _strlen(datas->environ[i]));
		write(STDOUT_FILENO, "\n", 1);
	}

	return (1);
}
