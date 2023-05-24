#include "main.h"

/**
 * _putchar - write character
 * @c: the character
 * Return: 1
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * cat_keyval - create env string "key=val"
 * @key: key
 * @val: value
 * Return: pointer to string
 */

char *cat_keyval(char *key, char *val)
{
	char *env;

	env = malloc(sizeof(char) * (_strlen(key) + _strlen(val) + 2));
	_strcpy(env, key);
	_strcat(env, "=");
	_strcat(env, val);
	_strcat(env, "\0");

	return (env);
}

/**
 * _setenv - get env val pointer by key
 * @datas: datas
 * @key: the key
 * @val: the val
 * Return: o if not the key and val position if is key
 */

void _setenv(data *datas, char *key, char *val)
{
	char *var;
	int i;

	for (i = 0; datas->environ[i]; i++)
	{
		var = malloc(sizeof(char) * (_strlen(datas->environ[i]) + 1));
		_strcpy(var, datas->environ[i]);

		if (_strcmp(strtok(var, "="), key) == 0)
		{
			free(datas->environ[i]);
			datas->environ[i] = cat_keyval(key, val);
			datas->envsize += 1;

			free(var);
			return;
		}
		free(var);
	}

	datas->environ = realloc_da(datas->environ, i, i + 2);
	datas->environ[i] = cat_keyval(key, val);
	datas->environ[i + 1] = NULL;
	datas->envsize += 1;
}
