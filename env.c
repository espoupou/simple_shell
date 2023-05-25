#include "main.h"

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
	if (datas->args[1] == NULL || datas->args[2] == NULL)
	{
		printf("err setenv\n");
		return (1);
	}

	_setenv(datas, datas->args[1], datas->args[2]);
	return (1);
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
		return (1);

	for (i = 0; datas->environ[i]; i++)
	{
		var = malloc(sizeof(char) * (_strlen(datas->environ[i]) + 1));
		_strcpy(var, datas->environ[i]);
		if (_strcmp(_strtok(var, "="), datas->args[1]) == 0)
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

/**
 * _getenv - get env val by key
 * @key: the key
 * @datas: datas
 * Return: value pointer
 */

char *_getenv(char *key, data *datas)
{
	int i, j;

	for (i = 0; datas->environ[i]; i++)
	{
		/* compare name and key */
		for (j = 0; datas->environ[i][j] != '='; j++)
		{
			if (datas->environ[i][j] != key[j])
			{
				j = 0;
				break;
			}
		}

		if (j == 0)
			continue;

		j++; /* skip the equal sign */
		return (datas->environ[i] + j);
	}
	return (NULL);
}

/**
 * free_env - frees data structure
 * @datas: data
 * Return: no return
 */
void freeenv(data *datas)
{
	unsigned int i;

	for (i = 0; datas->environ[i]; i++)
	{
		free(datas->environ[i]);
	}

	free(datas->environ);
}
