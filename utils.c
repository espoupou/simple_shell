#include "main.h"

/**
 * _putchar - write character
 * @c: the character
 * Return: 1
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * cat_keyenv - create env string "key=val"
 * @env: env var pointer
 * @key: key
 * @val: value
 * Return: pointer to string
 */

char *cat_keyval(char *key, char *val)
{
	char *env;

	env = malloc(sizeof(char) * (_strlen(key) + _strlen(val) + 2));
	_strcpy(env, key);
	_strcat(env, "=");
	_strcat(env, val);
	_strcat(env, "\0");

	return (env);
}
