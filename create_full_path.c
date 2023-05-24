#include "main.h"
/**
 * create_full_path -> prints full dir path
 * @dir: directory
 * @command: command
 *
 * Return: full dir path
 */
char *create_full_path(const char *dir, const char *command)
{
	size_t dir_len, command_len;
	char *full_path;
	if (dir == NULL || command == NULL)
		return (NULL);

	dir_len = strlen(dir);
	command_len = strlen(command);

	full_path = malloc((dir_len + command_len + 2) * sizeof(char));

	if (full_path == NULL)
	{
		perror("Error");
		exit(EXIT_FAILURE);
	}
	strncpy(full_path, dir, dir_len);

	if (dir[dir_len - 1] != '/')
	{
		full_path[dir_len] = '/';
	}
	dir_len++;
	strncpy(full_path + dir_len, command, command_len);

	full_path[dir_len + command_len] = '\0';
	return (full_path);
}
