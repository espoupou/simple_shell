#include "main.h"

/**
 * builtin_handler - choose builtin function
 * @input: inputed line
 * Return: status 0 or 1
 */

int (*builtin_handler(char *input))(data *datas)
{
	builtin builtins[] = {
		{"exit", _exit},
		{NULL, NULL}
		};
	int i;

	for (i = 0; builtin[i].name != NULL; i++)
	{
		if (_strcmp(builtin[i].name, cmd) == 0)
			break;
	}
	return (builtins[i].f);
}

/**
 * _exit - exit the program
 * @datas: datas
 * Return: always 0
 */

int _exit(data *datas)
{
	return (0);
}
