#include "shell.h"
/**
 * check_env - checks for the env built in command
 * @cmd : tokenized command
 * Return: 0 if command is found
 */
int check_env(char *cmd)
{
	return (strcmp(cmd, "env") == 0);
}
