#include "main.h"

/**
 * _exec - execute cmd
 * @datas: datas
 * Return: nothing
 */

void _exec(data *datas)
{
	pid_t pid;
	int state;
	char *environ[] = { NULL };

	pid = fork();
	if (pid == 0)
	{
		execve(datas->input, datas->args, environ);
		perror(datas->av[0]);
	}
	else if (pid < 0)
	{
		perror(datas->av[0]);
	}
	else
	{
		waitpid(pid, &state, 0);
	}
}
