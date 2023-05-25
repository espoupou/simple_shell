#include "main.h"

/**
 * _sigint - Handle the crtl + c call in prompt
 * @sig: Signal handler
 */
void _sigint(int sig)
{
	(void)sig;
	write(STDOUT_FILENO, "\n:)$ ", 5);
}
