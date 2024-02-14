#include "shell.h"
/**
 * exit_shell - exits shell
 * @cmd : command
 * Return: Success(0)
 */
int exit_shell(char *cmd)
{
	return (strcmp(cmd, "exit") == 0);
}
