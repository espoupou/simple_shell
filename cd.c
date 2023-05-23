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
