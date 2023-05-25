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

	datas.av = av;
	datas.counter = 1;
	init_env(&datas);
	shell_loop(&datas);

	return (0);
}
