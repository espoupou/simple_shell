#ifndef __MAIN_H__
#define __MAIN_H__

#define UNUSED(x) (void)(x)

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <limits.h>
#include <sys/stat.h>

/* Poinngs called the "environment" */
extern char **environ;

/**
 * struct data - datas
 * @av: argument vector from shell
 * @input: input command
 * @args: input command in array
 * @environ: env variable
 * @envsize: @environ size
 * @status: last status of the shell
 * @counter: lines counter
 * @pid: main program pid
 * @stream: the input stream
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
	int status;
	int counter;
	char *pid;
	FILE *stream;
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

/**
 * struct r_var_l - single linked list
 * @len_var: length of the variable
 * @val: value of the variable
 * @len_val: length of the value
 * @next: next node
 * Description: single linked list to store variables
 */

typedef struct r_var_l
{
	int len_var;
	char *val;
	int len_val;
	struct r_var_l *next;
} r_var;

/* shell_loop.c */
char *_clean(char *input);
int parse_args(char *input, data *datas);
void shell_loop(data *datas);
void free_args(data *datas);

/* _exec.c: execution heart */
int _exec(data *datas);
int is_executable(data *datas);
char *_which(char *cmd, data *datas);
int is_cdir(char *path, int *i);
int check_error_cmd(char *dir, data *datas);

/* utils.c: utilities */
int _putchar(char c);
char *cat_keyval(char *key, char *val);
void _setenv(data *datas, char *key, char *val);
void rev_str(char *s);

/* utils_1.c */
r_var *add_rvar_node(r_var **head, int lvar, char *val, int lval);
void free_rvar_list(r_var **head);
int isspaces(char *input);

/* char_utils.c: char functions utilities */
int _strlen(const char *s);
int _strcmp(char *s1, char *s2);
char *_strcpy(char *dest, char *src);
char *_strncpy(char *dest, char *src, int n);
char *_strcat(char *dest, char *src);

/* char_utilis_1.c: */
char *_strdup(const char *s);
int _charchk(char str[], const char *delim);
char *_strtok(char str[], const char *delim);
char *_strchr(char *s, char c);
unsigned int _strspn(char *s, char *accept);

/* char_utils_2.c */
char *_itoa(int n);
int get_len(int n);
int _atoi(char *s);
int _isdigit(const char *s);

/* mem_utils.c: memory manipulation utilities */
char **realloc_da(char **p, int old_size, int new_size);
char *_memcpy(char *dest, const char *src, unsigned int n);

/* inputs.c: get user input utilities */
int _getline(data *datas);

/* buildin.c: buildin functions - extend to env.c, cd.c */
int (*builtin_handler(char *input))(data *datas);
int __exit(data *datas);
int __env(data *datas);

/* env.c: buildin env functions */
void init_env(data *datas);
int __setenv(data *datas);
int __unsetenv(data *datas);
char *_getenv(char *key, data *datas);
void free_env(data *datas);

/* cd.c: buidin cd functions */
int __cd(data *datas);
void cd_home(data *datas);
void cd_prev(data *datas);
void cd_dot(data *datas);
void cd_to(data *datas);

/* error_handler.c: handle error */
int get_error(data *datas, int eval);
char *error_env(data *datas);
char *error_path_126(data *datas);
char *error_not_found(data *datas);
char *error_exit_shell(data *datas);

/* error_handler_1.c: handle error */
char *error_get_cd(data *datas);
char *error_open_stream(data *datas);
/* _sigint.c: ^C escape */
void _sigint(int sig);

/* var_replace.c */
char *rep_var(char *input, data *datas);

#endif
