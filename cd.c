#include "main.h"

/**
 * __cd - change directory buildin
 * @datas: datas
 * Return: status 0 or 1
 */

int __cd(data *datas)
{
	if (datas->args[1] == NULL)
	{
		cd_home(datas);
		return (1);
	}

	if (_strcmp(datas->args[1], "-") == 0)
	{
		cd_prev(datas);
		return (1);
	}

	if (_strcmp(datas->args[1], ".") == 0 || _strcmp(datas->args[1], "..") == 0)
	{
		cd_dot(datas);
		return (1);
	}

	return (1);
}

/**
 * cd_home - cd to home directory
 * @datas: datas
 * Return: nothing
 */

void cd_home(data *datas)
{
	char *home, pwd[PATH_MAX];

	getcwd(pwd, sizeof(pwd));

	home = _getenv("HOME", datas);
	if (home == NULL)
	{
		_setenv(datas, "OLDPWD", pwd);
		return;
	}

	if (chdir(home) == -1)
	{
		printf("err cd home\n");
		return;
	}
	_setenv(datas, "OLDPWD", pwd);
	_setenv(datas, "PWD", home);
}

/**
 * cd_prev ) cd to previous directory
 * @datas: datas
 * Return : nothing
 */

void cd_prev(data *datas)
{
	char pwd[PATH_MAX], *oldpwd;

	getcwd(pwd, sizeof(pwd));

	oldpwd = _strdup(_getenv("OLDPWD", datas));
	if (oldpwd == NULL)
		oldpwd = pwd;

	_setenv(datas, "OLDPWD", pwd);

	if (chdir(oldpwd) == -1)
	{
		_setenv(datas, "PWD", pwd);
		write(STDOUT_FILENO, pwd, _strlen(pwd));
	}
	else
	{
		_setenv(datas, "PWD", oldpwd);
		write(STDOUT_FILENO, oldpwd, _strlen(oldpwd));
	}

	write(STDOUT_FILENO, "\n", 1);
}

/**
 * cd_dot - cd to parent or current dir
 * @datas: datas
 * Return: nothing
 */

void cd_dot(data *datas)
{
	char pwd[PATH_MAX];
	char *_pwd, *p, *parent;

	getcwd(pwd, sizeof(pwd));
	_pwd = _strdup(pwd);
	_setenv(datas, "OLDPWD", _pwd);

	if (_strcmp(datas->args[1], ".") == 0)
	{
		_setenv(datas, "PWD", pwd);
		return;
	}

	if (_strcmp(_pwd, "/") == 0)
		return;

	p = _pwd;
	rev_str(p);

	if (_strtok(p, "/") != NULL)
	{
		parent = _strtok(NULL, "\0");
		if (parent != NULL)
		{
			rev_str(parent);
			chdir(parent);
			_setenv(datas, "PWD", parent);
			free(_pwd);
			return;
		}
	}
	chdir("/");
	_setenv(datas, "PWD", "/");
	free(_pwd);
}
