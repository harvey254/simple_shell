#include "shell.h"
/**
 * execute_command - executes commands
 * @command: command
 * Return no value
 */
void execute_command(char *command)
{
	char *args[2];
	char *token;
	int status;
	char **env_var;
	char *path;
        char *path_copy ;
        char *dir;
	char full_path[256];

	pid_t pid;

	if (command == NULL || strspn(command, " \t\n") == strlen(command))
		return;
	if (strcmp(command, "exit") == 0)
	{
		token = strtok(NULL, " ");
		status = 0;
		if (token != NULL)
		{
			status = atoi(token);
		}
		exit(status);
	}
	if (strcmp(command, "env") == 0)
	{
		env_var = environ;
		while (*env_var != NULL)
		{
			printf("%s\n", *env_var);
			env_var++;
		}
		return;
	}
	parse_cmd(command, args);
	pid = fork();
	if (pid == -1)
	{
		perror("fork");
	}
	else if (pid == 0)
	{
		path = getenv("PATH");
		path_copy = strdup(path);
		dir = strtok(path_copy, ":");
		while (dir != NULL)
		{
			if (strchr(args[0], '/') == NULL)
			{
				snprintf(full_path, sizeof(full_path), "/bin/%s",  args[0]);
				args[0] = command;
				args[1] = NULL;
				execve(full_path, args, environ);
				dir = strtok(NULL, ":");
				perror("execve");
				exit(EXIT_FAILURE);

			}
			else
			{
				snprintf(full_path, sizeof(full_path), "%s", args[0]);
				args[0] = command;
				args[1] = NULL;
				execve(full_path, args, environ);
				dir = strtok(NULL, ":");
				perror("execve");
				exit(EXIT_FAILURE);
			}
		}
	}
	else
	{
		wait(NULL);
	}
}
