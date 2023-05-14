#ifndef __MAIN_H__
#define __MAIN_H__

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/* Poinngs called the "environment" */
extern char **environ;

/**
 * struct data - datas
 * @av: argument vector from shell
 * @input: input command
 * @args: input command in array
 * Description: we need shell program name for handling errors
 * also put input here to minimize functions parameters
 */
typedef struct data
{
	char **av;
	char *input;
	char *args[2];
} data;

/* shell_loop.c */
int get_cmd(char **input);
char *_clean(char *input);
void shell_loop(data *datas);

/* _exec.c */
void _exec(data *datas);

/* utils.c */
int _strcmp(char *s1, char *s2);

#endif
