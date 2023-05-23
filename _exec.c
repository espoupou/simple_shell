#include "main.h"

/**
 * _exec - execute cmd
 * @datas: datas
 * Return: nothing
 */

int _exec(data *datas)
{
	pid_t pid;
	int state;
/*	char *environ[] = { NULL }; */

	pid = fork();
	if (pid == 0)
	{
		execve(datas->args[0], datas->args, environ);
		perror(datas->av[0]);
		exit(0);
	}
	else if (pid < 0)
	{
		perror(datas->av[0]);
	}
	else
	{
		do {
			waitpid(pid, &state, WUNTRACED);
		} while (!WIFEXITED(state) && !WIFSIGNALED(state));
	}

	return (1);
}
