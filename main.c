#include "main.h"

/**
 * main - simple shell entry point
 * @ac: argument count
 * @av: argument vecto
 * Return: always 0
 */

int main(int ac, char **av)
{
	data datas;
	(void) ac;

	signal(SIGINT, _sigint);

	datas.av = av;
	datas.args = NULL;
	datas.counter = 1;
	datas.status = 0;
	datas.pid = _itoa(getpid());
	datas.stream = NULL;

	if (ac == 1)
		datas.stream = stdin;
	else
	{
		datas.stream = fopen(av[1], "r");
		if (datas.stream == NULL)
		{
			datas.status = 127;
			datas.input = error_open_stream(&datas);
			write(STDERR_FILENO, datas.input, _strlen(datas.input));
		}
	}

	if (datas.stream)
	{
		init_env(&datas);
		shell_loop(&datas);
		free_env(&datas);
	}

	free_args(&datas);
	free(datas.pid);

	if (datas.status < 0)
		return (255);
	return (datas.status);
}
