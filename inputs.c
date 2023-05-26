#include "main.h"

#define BUF_SIZE 256

/**
 * _getline - get inputed line
 * @datas: datas
 * Return: the size
 */

int _getline(data *datas)
{
	static char *buffer = NULL;
	static int index = BUF_SIZE;
	char buf[BUF_SIZE] = "\0";
	int size = 0, i = BUF_SIZE + 1, count = 0;
	char *input = NULL;
	int loop = 1;

	if (size == 0 && index >= (BUF_SIZE - 1))
	{
		index = 0;
		while (loop)
		{
			_memset(buf, 0, BUF_SIZE + 1);
			i = read(STDIN_FILENO, buf, BUF_SIZE);
			buffer = realloc_a(buffer, size, size + i + 1);
			size += i;
			_strcat(buffer, buf);

			if (buf[i - 1] == '\n')
				loop = 0;
		}

		buffer[size] = '\0';
/*		_clean(buffer);*/

	}

	if (index <= BUF_SIZE && buffer[index] != '\0')
	{
		input = malloc((sizeof(char) * BUF_SIZE));
		if (input == NULL)
			return (0);

		while (buffer[index] != '\n' && buffer[index] != '\0')
		{
			if (count >= BUF_SIZE - 1)
		{
printf("%d\n", count);
				input = realloc_a(input, count, count + 2);
				if (input == NULL)
					return (0);
}
			input[count++] = buffer[index++];
		}
		input[count] = '\0';

		if (buffer[index] != '\0')
			index = index + 1;
		if (buffer[index] == '\0')
		{
			free(buffer);
			buffer = NULL;
			size = 0;
			index = BUF_SIZE;
		}
		datas->input = input;
	}

	if (count == 0 && input != NULL && *input != EOF)
		count++;

	return (count);
}


/**
 * _getline - get inputed line
 * @datas: datas
 * Return: the size
 */

int _getline2(data *datas)
{
	char c = '\0', *q;
	int i = 0;
	ssize_t size;

	datas->input = malloc(sizeof(char) * 256);
	if (datas->input == NULL)
		return (0);
	_memset(datas->input, 0, 256);

	while (c != '\n' && c != EOF)
	{
		size = read(STDIN_FILENO, &c, 1);
		if (size == 0)
		{
	/*		_putchar('\n'); */
			return (0);
		}
		if (i == 0 && (c == ' ' || c == '\t'))
			continue;

		if (i > 254)
		{
			/* realloc space */
			q = malloc(sizeof(char) * (i + 2)); /* the new char and \0 */

			if (q == NULL)
			{
				free(datas->input);
printf("limits reached");
				return (0);
			}
			_memset(q, 0, i + 2);
			_strncpy(q, datas->input, i);
			free(datas->input);
			datas->input = q;
		}

		datas->input[i] = c;
		i++;
	}

	*(datas->input + i - 1) = '\0';
printf("\n - %s -\n\n", datas->input);
	return (i + 1);
}
