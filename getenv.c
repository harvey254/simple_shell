#include "main.h"
/**
 * _getenv -> 
 * @name:
 * @env:
 *
 * Return:
 */
char *_getenv(const char *name, char **env)
{
	int i;
	size_t name_len;
	if (name == NULL || env == NULL)
		return NULL;
	name_len = strlen(name);

	for (i = 0; env[i] != NULL; i++)
	{
		if (strncmp(name, env[i], name_len) == 0 && env[i][name_len] == '=')
			return (env[i] + name_len + 1);
	}

	return (NULL);
}
