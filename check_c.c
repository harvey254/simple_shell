#include "main.h"
/**check_command_in_path ->
 * @commmand
 * @path
 *
 * Return: path
 */
char *check_command_in_path(const char *command, const char *path)
{
	char *path_copy, *dir, *full_path;
	if (command == NULL || path == NULL)
		return NULL;

	path_copy = strdup(path);

	if (path_copy == NULL)
	{
		perror("Error");
		exit(EXIT_FAILURE);
	}
	dir = strtok(path_copy, ":");
	while (dir)
	{
		full_path = create_full_path(dir, command);

		if (access(full_path, X_OK) == 0)
		{
			free(path_copy);
			return (full_path);
		}
		free(full_path);
		dir = strtok(NULL, ":");
	}
	free(path_copy);

	return NULL;
}
