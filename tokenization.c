#include "shell.h"
/**
 * parse_cmd - tokenize command inputs
 * @cmd: command
 * @args: string of arguments
 * Return: number of tokenized arguments
 */
int parse_cmd(char *cmd, char *args[])
{
	char *token = strtok(cmd, " ");
	int i = 0;

	while (token != NULL)
	{
		args[i++] = token;
		token = strtok(NULL, " ");
	}
	args[i] = NULL;

	return (i);
}
