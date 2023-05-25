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

	init_env(&datas);
	shell_loop(&datas);
	free_env(&datas);

	free_args(&datas);

	if (datas.status < 0)
		return (255);
	return (datas.status);
}
