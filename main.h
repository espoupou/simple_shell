#ifndef __MAIN_H__
#define __MAIN_H__

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * struct data - datas
 * @av: argument vector from shell
 * @input: input command
 * Description: we need shell program name for handling errors
 * also put input here to minimize functions parameters
 */
typedef struct data
{
	char **av;
	char *input;
} data;

/* shell_loop.c */
int get_cmd(char **input);
void shell_loop(data *datas);

#endif
