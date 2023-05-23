#include "main.h"
#include <string.h>

/**
 * init_env - iniitialize env in datas
 * @datas: datas
 * Return: nothing
 */

void init_env(data *datas)
{
	int i, j = 0;

	for (i = 0; environ[i]; i++)
		;
	datas->environ = malloc(sizeof(char *) * (i + 1));

	while (environ[j] != NULL)
	{
		for (i = 0; environ[j][i]; i++)
			;
		datas->environ[j] = malloc(sizeof(char) * (i + 1));
		_strcpy(datas->environ[j], environ[j]);
		j++;
	}
	datas->environ[j] = NULL;
	datas->envsize = j;
}

/**
 * __setenv - set env var
 * @datas: datas
 * Return: status 0 or 1
 */

int __setenv(data *datas)
{
	int i;
	char *var;

	if (datas->args[1] == NULL || datas->args[2] == NULL)
	{
		printf("err setenv\n");
		return (1);
	}

	for (i = 0; datas->environ[i]; i++)
	{
		var = malloc(sizeof(char) * (_strlen(datas->environ[i]) + 1));
		_strcpy(var, datas->environ[i]);

		if (_strcmp(strtok(var, "="), datas->args[1]) == 0)
		{
			free(datas->environ[i]);
			datas->environ[i] = cat_keyval(datas->args[1], datas->args[2]);
			datas->envsize += 1;

			free(var);
			return (1);
		}
		free(var);
	}

	datas->environ = realloc_da(datas->environ, i, i+2);
	datas->environ[i] = cat_keyval(datas->args[1], datas->args[2]);
	datas->environ[i + 1] = NULL;
	datas->envsize += 1;
	return (1);
}

/**
 * cat_keyenv - create env string "key=val"
 * @env: env var pointer
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
 * __unsetenv - unset env variable
 * @datas: datas
 * Return: status 0 or 1
 */

int __unsetenv(data *datas)
{
	char *var, **env;
	int i, j, k;

	if (datas->args[1] == NULL)
	{
		return (1);
	}

	for (i = 0; datas->environ[i]; i++)
	{
		var = malloc(sizeof(char) * (_strlen(datas->environ[i]) + 1));
		_strcpy(var, datas->environ[i]);

		if (_strcmp(strtok(var, "="), datas->args[1]) == 0)
		{
			free(var);

			env = malloc(sizeof(char *) * datas->envsize - 1);
			if (env == NULL)
				return (0);

			free(datas->environ[i]);
			for (j = 0, k = 0; datas->environ[j]; j++)
			{
				if (i != j)
				{
					env[k] = datas->environ[j];
					k++;
				}
			}
			env[k] = NULL;

			free(datas->environ);
			datas->environ = env;
			datas->envsize--;

			return (1);
		}
		free(var);
	}

	printf("err unsetenv\n");
	return (1);
}
