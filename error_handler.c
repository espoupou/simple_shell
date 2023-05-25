#include "main.h"

/**
 * get_error - error handler
 * @datas: datas
 * @eval: error value
 * Return: error
 */
int get_error(data *datas, int eval)
{
	char *error;

	switch (eval)
	{
	case -1:
		error = error_env(datas);
		break;
	case 126:
		error = error_path_126(datas);
		break;
	case 127:
		error = error_not_found(datas);
		break;
	case 2:
		if (_strcmp("exit", datas->args[0]) == 0)
			error = error_exit_shell(datas);
		else if (_strcmp("cd", datas->args[0]) == 0)
			error = error_get_cd(datas);
		break;
	}

	if (error)
	{
		write(STDERR_FILENO, error, _strlen(error));
		free(error);
	}

	datas->status = eval;
	return (eval);
}

/**
 * error_env - error message for env
 * @datas: datas
 * Return: error message
 */
char *error_env(data *datas)
{
	int length;
	char *error;
	char *ver_str;
	char *msg;

	ver_str = _itoa(datas->counter);
	msg = ": Unable to add/remove from environment\n";
	length = _strlen(datas->av[0]) + _strlen(ver_str);
	length += _strlen(datas->args[0]) + _strlen(msg) + 4;
	error = malloc(sizeof(char) * (length + 1));
	if (error == 0)
	{
		free(error);
		free(ver_str);
		return (NULL);
	}

	_strcpy(error, datas->av[0]);
	_strcat(error, ": ");
	_strcat(error, ver_str);
	_strcat(error, ": ");
	_strcat(error, datas->args[0]);
	_strcat(error, msg);
	_strcat(error, "\0");
	free(ver_str);

	return (error);
}

/**
 * error_path_126 - denied permission.
 * @datas: datas
 * Return: The error string.
 */

char *error_path_126(data *datas)
{
	int length;
	char *ver_str;
	char *error;

	ver_str = _itoa(datas->counter);
	length = _strlen(datas->av[0]) + _strlen(ver_str);
	length += _strlen(datas->args[0]) + 24;
	error = malloc(sizeof(char) * (length + 1));
	if (error == 0)
	{
		free(error);
		free(ver_str);
		return (NULL);
	}
	_strcpy(error, datas->av[0]);
	_strcat(error, ": ");
	_strcat(error, ver_str);
	_strcat(error, ": ");
	_strcat(error, datas->args[0]);
	_strcat(error, ": Permission denied\n");
	_strcat(error, "\0");
	free(ver_str);
	return (error);
}

/**
 * error_not_found - cmd not found
 * @datas: datas
 * Return: Error message
 */
char *error_not_found(data *datas)
{
	int length;
	char *error;
	char *ver_str;

	ver_str = _itoa(datas->counter);
	length = _strlen(datas->av[0]) + _strlen(ver_str);
	length += _strlen(datas->args[0]) + 16;
	error = malloc(sizeof(char) * (length + 1));
	if (error == 0)
	{
		free(error);
		free(ver_str);
		return (NULL);
	}
	_strcpy(error, datas->av[0]);
	_strcat(error, ": ");
	_strcat(error, ver_str);
	_strcat(error, ": ");
	_strcat(error, datas->args[0]);
	_strcat(error, ": not found\n");
	_strcat(error, "\0");
	free(ver_str);
	return (error);
}

/**
 * *error_exit_shell - exit shell
 * @datas: datas
 * Return: Error message
 */

char *error_exit_shell(data *datas)
{
	int length;
	char *error;
	char *ver_str;

	ver_str = _itoa(datas->counter);
	length = _strlen(datas->av[0]) + _strlen(ver_str);
	length += _strlen(datas->args[0]) + _strlen(datas->args[1]) + 23;
	error = malloc(sizeof(char) * (length + 1));
	if (error == 0)
	{
		free(ver_str);
		return (NULL);
	}
	_strcpy(error, datas->av[0]);
	_strcat(error, ": ");
	_strcat(error, ver_str);
	_strcat(error, ": ");
	_strcat(error, datas->args[0]);
	_strcat(error, ": Illegal number: ");
	_strcat(error, datas->args[1]);
	_strcat(error, "\n\0");
	free(ver_str);

	return (error);
}
