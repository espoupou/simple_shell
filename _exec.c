#include "main.h"

/**
 * _exec - execute cmd
 * @datas: datas
 * Return: nothing
 */

int _exec(data *datas)
{
	pid_t pid;
	int state, exec;
	char *dir;

	exec = is_executable(datas);
	if (exec == -1)
		return (1);
	if (exec == 0)
	{
		dir = _which(datas->args[0], datas);
		if (check_error_cmd(dir, datas) == 1)
			return (1);
	}

	pid = fork();
	if (pid == 0)
	{
		if (exec == 0)
			dir = _which(datas->args[0], datas);
		else
			dir = datas->args[0];

		execve(dir, datas->args, datas->environ);
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

	datas->status = state / 256;
	return (1);
}

/**
 * is_executable - if is executable
 * @datas: datas
 * Return: status
 */

int is_executable(data *datas)
{
	struct stat st;
	int i;
	char *input;

	input = datas->args[0];
	for (i = 0; input[i]; i++)
	{
		if (input[i] == '.')
		{
			if (input[i + 1] == '.')
				return (0);
			if (input[i + 1] == '/')
				continue;
			else
				break;
		}
		else if (input[i] == '/' && i != 0)
		{
			if (input[i + 1] == '.')
				continue;
			i++;
			break;
		}
		else
			break;
	}
	if (i == 0)
		return (0);

	if (stat(input + i, &st) == 0)
	{
		return (i);
	}

	return (-1);
}

/**
 * _which - locate cmd
 * @cmd: command
 * @datas: datas
 * Return: path
 */

char *_which(char *cmd, data *datas)
{
	char *path, *ptr_path, *token_path, *dir;
	int len_dir, len_cmd, i;
	struct stat st;

	path = _getenv("PATH", datas);
	if (path)
	{
		ptr_path = _strdup(path);
		len_cmd = _strlen(cmd);
		token_path = _strtok(ptr_path, ":");
		i = 0;
		while (token_path != NULL)
		{
			if (is_cdir(path, &i))
				if (stat(cmd, &st) == 0)
					return (cmd);
			len_dir = _strlen(token_path);
			dir = malloc(len_dir + len_cmd + 2);
			_strcpy(dir, token_path);
			_strcat(dir, "/");
			_strcat(dir, cmd);
			_strcat(dir, "\0");
			if (stat(dir, &st) == 0)
			{
				free(ptr_path);
				return (dir);
			}
			free(dir);
			token_path = _strtok(NULL, ":");
		}
		free(ptr_path);
		if (stat(cmd, &st) == 0)
			return (cmd);
		return (NULL);
	}
	if (cmd[0] == '/')
		if (stat(cmd, &st) == 0)
			return (cmd);
	return (NULL);
}

/**
 * is_cdir - checks ":" if is in the current directory.
 * @path: type char pointer char.
 * @i: type int pointer of index.
 * Return: 1 if the path is searchable in the cd, 0 otherwise.
 */
int is_cdir(char *path, int *i)
{
	if (path[*i] == ':')
		return (1);

	while (path[*i] != ':' && path[*i])
	{
		*i += 1;
	}

	if (path[*i])
		*i += 1;

	return (0);
}

/**
 * check_error_cmd - verifies if user has permissions to access
 * @dir: destination directory
 * @datas: datas
 * Return: 1 if there is an error, 0 if not
 */
int check_error_cmd(char *dir, data *datas)
{
	if (dir == NULL)
	{
		get_error(datas, 127);
		return (1);
	}

	if (_strcmp(datas->args[0], dir) != 0)
	{
		if (access(dir, X_OK) == -1)
		{
			get_error(datas, 126);
			free(dir);
			return (1);
		}
		free(dir);
	}
	else
	{
		if (access(datas->args[0], X_OK) == -1)
		{
			get_error(datas, 126);
			return (1);
		}
	}

	return (0);
}
