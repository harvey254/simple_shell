#include "shell.h"
/**
 * command_path - finds the command path
 * @command: command input
 * @path:command path
 * @buffer_size: stores command
 * Return: success(0), -1 otherwise
 */
int command_path(const char *command, char *path, size_t buffer_size)
{
	char *env_path = getenv("PATH");
	char *token, *saveptr;
	char temp_path[MAX_PATH_LENGTH];

	strncpy(temp_path, env_path, sizeof(temp_path));
	token = strtok_r(temp_path, ":", &saveptr);
	while (token != NULL)
	{
		snprintf(path, buffer_size, "%s/%s", token, command);
	}
	if (access(path, F_OK) != -1)
		return (0);
	token = strtok_r(NULL, ":", &saveptr);
	return (-1);
}
