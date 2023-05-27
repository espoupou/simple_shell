#include "main.h"

/**
 * strcat_cd - function that concatenates the message for cd error
 * @datas: datas
 * @msg: message to print
 * @error: output message
 * @ver_str: counter lines
 * Return: error message
 */

char *strcat_cd(data *datas, char *msg, char *error, char *ver_str)
{
	char *illegal_flag;

	_strcpy(error, datas->av[0]);
	_strcat(error, ": ");
	_strcat(error, ver_str);
	_strcat(error, ": ");
	_strcat(error, datas->args[0]);
	_strcat(error, msg);
	if (datas->args[1][0] == '-')
	{
		illegal_flag = malloc(3);
		illegal_flag[0] = '-';
		illegal_flag[1] = datas->args[1][1];
		illegal_flag[2] = '\0';
		_strcat(error, illegal_flag);
		free(illegal_flag);
	}
	else
	{
		_strcat(error, datas->args[1]);
	}

	_strcat(error, "\n");
	_strcat(error, "\0");
	return (error);
}

/**
 * error_get_cd - error message for cd command in get_cd
 * @datas: datas
 * Return: Error message
 */

char *error_get_cd(data *datas)
{
	int length, len_id;
	char *error, *ver_str, *msg;

	ver_str = _itoa(datas->counter);
	if (datas->args[1][0] == '-')
	{
		msg = ": Illegal option ";
		len_id = 2;
	}
	else
	{
		msg = ": can't cd to ";
		len_id = _strlen(datas->args[1]);
	}

	length = _strlen(datas->av[0]) + _strlen(datas->args[0]);
	length += _strlen(ver_str) + _strlen(msg) + len_id + 5;
	error = malloc(sizeof(char) * (length + 1));

	if (error == 0)
	{
		free(ver_str);
		return (NULL);
	}

	error = strcat_cd(datas, msg, error, ver_str);

	free(ver_str);

	return (error);
}

/**
 * error_open_stream -  error message for stream opening
 * @datas: datas
 * Return: error message
 */

char *error_open_stream(data *datas)
{
	int length;
	char *error;

	length = _strlen(datas->av[0]);
	length += _strlen(datas->av[1]) + 17;
	error = malloc(sizeof(char) * (length + 1));
	if (error == 0)
	{
		free(error);
		return (NULL);
	}
	_strcpy(error, datas->av[0]);
	_strcat(error, ": 0: Can't open ");
	_strcat(error, datas->av[1]);
	_strcat(error, "\n\0");

	return (error);
}
