#include "shell.h"
/**
 * command_path - finds the command path
 * @command: string command
 * @full_path: path variable
 * @size: size of command
 * Return: command found(1), -1 otherwise
 */
int command_path(const char *command, char *full_path, size_t size)
{
	char *path = getenv("PATH");
	char *token;

	if (path == NULL)
	{
		fprintf(stderr, "Error: PATH environment variable not set\n");
		return (-1);
	}
	token = strtok(path, ":");
	while (token != NULL)
	{
		snprintf(full_path, size, "%s/%s", token, command);
		if (access(full_path, X_OK) == 0)
		{
			return (0);
		}
		token = strtok(NULL, ":");
	}
	fprintf(stderr, "Command not found in PATH: %s\n", command);
	return (-1);
}
