#ifndef __MAIN_H__
#define __MAIN_H__

#define UNUSED(x) (void)(x)

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
	char **args;
	char **environ;
} data;

/**
 * struct builtin - Builtins
 * @name: name of builtin
 * @f: function associed
 */

typedef struct builtin
{
	char *name;
	int (*f)(data *datas);
} builtin;

/* shell_loop.c */
int get_cmd(char **input);
char *_clean(char *input);
int parse_args(char *input, data *datas);
void shell_loop(data *datas);

/* _exec.c */
int _exec(data *datas);

/* utils.c */
int _strcmp(char *s1, char *s2);
char *_strcpy(char *dest, char *src);
int _putchar(char c);
char *_strncpy(char *dest, char *src, int n);
char *_strcat(char *dest, char *src);

/* char_utils.c */
int _strlen(char *s);

/* mem_utils.c */
char **realloc_da(char **p, int old_size, int new_size);

/* inputs.c */
int _getline(data *datas);

/* buildin.c */
int (*builtin_handler(char *input))(data *datas);
int __exit(data *datas);
int __env(data *datas);

/* env.c */
void init_env(data *datas);
int __setenv(data *datas);
char *cat_keyval(char *key, char *val);

#endif
