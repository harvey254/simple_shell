#include "main.h"
/**
 * _getenv -> get environment variable
 * @name: string value
 * @env: environment variable
 *
 * Return: environment variable
 */
char *_getenv(const char *name, char **env)
{
	int i;
	size_t name_len;

	if (name == NULL || env == NULL)
		return (NULL);
	name_len = strlen(name);

	for (i = 0; env[i] != NULL; i++)
	{
		if (strncmp(name, env[i], name_len) == 0 && env[i][name_len] == '=')
			return (env[i] + name_len + 1);
	}

	return (NULL);
}
