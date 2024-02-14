#include "shell.h"
/**
 * print_env - prints the current environment
 *
 * Return: no value
 */
void print_env(void)
{
	int i;

	for (i = 0; environ[i] != NULL; i++)
	{
		printf("%s\n", environ[i]);
	}
}
