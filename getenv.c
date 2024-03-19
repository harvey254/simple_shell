#include "shell.h"

/**
  * _getenv - Gets an environment variable
  * @identity: The variable to find in the system environment
  *
  * Return: elements of environment variable
  */
char *_getenv(const char *identity)
{
	char *env_var = NULL;
	int i = 0;
	while (environ[i])
	{
		if (strncmp(identity, environ[i], strlen(identity)) == 0)
		{
			env_var = strdup(environ[i]);
			while (*env_var != '=')
				env_var++;

			++env_var;
			return (env_var);
		}
		i++;
	}

	return (NULL);
}
