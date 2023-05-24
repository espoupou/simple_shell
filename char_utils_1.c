#include "main.h"

/**
 * _strdup - duplicate string
 * @s: the string
 * Return: duplicated
 */

char *_strdup(const char *s)
{
	char *new;
	size_t len;

	len = _strlen(s);
	new = malloc(sizeof(char) * (len + 1));
	if (new == NULL)
		return (NULL);
	_memcpy(new, s, len + 1);
	return (new);
}

/**
 * _charchk - compare chars of strings
 * @str: input string.
 * @delim: delimiter.
 * Return: 1 if are equals, 0 if not.
 */
int _charchk(char str[], const char *delim)
{
	unsigned int i, j, k;

	for (i = 0, k = 0; str[i]; i++)
	{
		for (j = 0; delim[j]; j++)
		{
			if (str[i] == delim[j])
			{
				k++;
				break;
			}
		}
	}
	if (i == k)
		return (1);
	return (0);
}

/**
 * _strtok - split string
 * @str: the string
 * @delim: delimiter
 * Return: token
 */

char *_strtok(char str[], const char *delim)
{
	static char *splitted, *str_end;
	char *str_start;
	unsigned int i, bool;

	if (str != NULL)
	{
		if (_charchk(str, delim))
			return (NULL);
		splitted = str;
		i = _strlen(str);
		str_end = &str[i];
	}
	str_start = splitted;
	if (str_start == str_end)
		return (NULL);

	for (bool = 0; *splitted; splitted++)
	{
		/*Breaking loop finding the next token*/
		if (splitted != str_start)
			if (*splitted && *(splitted - 1) == '\0')
				break;
		/*Replacing delimiter for null char*/
		for (i = 0; delim[i]; i++)
		{
			if (*splitted == delim[i])
			{
				*splitted = '\0';
				if (splitted == str_start)
					str_start++;
				break;
			}
		}
		if (bool == 0 && *splitted)
			bool = 1;
	}
	if (bool == 0)
		return (NULL);
	return (str_start);
}

/**
 * _strchr -  locates a character in a string
 * @s: the string
 * @c: the character
 * Return: pointer to first occurence or NULL
 */

char *_strchr(char *s, char c)
{
	int i;

	for (i = 0; s[i] && s[i] != c; i++)
		;

	if (s[i] == c)
		return (s + i);
	return (NULL);
}

/**
 * _strspn -  gets the length of a prefix substring.
 * @s: the string
 * @accept: acceptable byte
 * Return: the length
 */

unsigned int _strspn(char *s, char *accept)
{
	unsigned int i = 0;

	while (s[i] && _strchr(accept, s[i]))
		i++;

	return (i);
}
