#include "main.h"
/**
 * printenv -> prints environment
 *
 * Return: no value
 */
void printenv(void)
{
	int i;
	char **env = environ;

	while (env[i])
	{
		write(STDOUT_FILENO, (const void *)env[i], strlen(env[i]));
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
}
