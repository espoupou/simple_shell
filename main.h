#ifndef __MAIN_H__
#define __MAIN_H__

#define UNUSED(x) (void)(x)

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <limits.h>

/* Poinngs called the "environment" */
extern char **environ;

/**
 * struct data - datas
 * @av: argument vector from shell
 * @input: input command
 * @args: input command in array
 * @environ: env variable
 * @envsize: @environ size
 * Description: we need shell program name for handling errors
 * also put input here to minimize functions parameters
 */

typedef struct data
{
	char **av;
	char *input;
	char **args;
	char **environ;
	int envsize;
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

/* _exec.c: execution heart */
int _exec(data *datas);

/* utils.c: utilities */
int _putchar(char c);
char *cat_keyval(char *key, char *val);
void _setenv(data *datas, char *key, char *val);
void rev_str(char *s);

/* char_utils.c: char functions utilities */
int _strlen(char *s);
int _strcmp(char *s1, char *s2);
char *_strcpy(char *dest, char *src);
char *_strncpy(char *dest, char *src, int n);
char *_strcat(char *dest, char *src);

/* char_utilis_1.c: */
char *_strdup(char *s);

/* mem_utils.c: memory manipulation utilities */
char **realloc_da(char **p, int old_size, int new_size);

/* inputs.c: get user input utilities */
int _getline(data *datas);

/* buildin.c: buildin functions - extend to env.c, cd.c */
int (*builtin_handler(char *input))(data *datas);
int __exit(data *datas);

/* env.c: buildin env functions */
void init_env(data *datas);
int __env(data *datas);
int __setenv(data *datas);
int __unsetenv(data *datas);
char *_getenv(char *key, data *datas);

/* cd.c: buidin cd functions */
int __cd(data *datas);
void cd_home(data *datas);
void cd_prev(data *datas);
void cd_dot(data *datas);

#endif
