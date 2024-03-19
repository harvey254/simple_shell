#include "shell.h"
/**
 * execute_command - executes commands
 * @command: command
 * Return no value
 */
void execute_command(char *command)
{
	char **args_ = NULL;
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
			free(command);
			free(token);
			exit(0);
		}
		status = atoi(token);
		if (status != 0)
		{
			free(command);
			free(token);
			exit (status);
		}
		else
		{

		exit(2);
		}
		free(command);
		free(token);
		exit(EXIT_SUCCESS);
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
	args_ = parse_cmd(command, " \t", sizeof(command));

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
			if (strchr(args_[0], '/') == NULL)
			{
				snprintf(full_path, sizeof(full_path), "/bin/%s",  args_[0]);
				args_[0] = command;
				args_[1] = NULL;
				execve(full_path, args_, environ);
				dir = strtok(NULL, ":");
				perror("execve");
				exit(EXIT_FAILURE);

			}
			else
			{
				snprintf(full_path, sizeof(full_path), "%s", args_[0]);
				args_[0] = command;
				args_[1] = NULL;
				execve(full_path, args_, environ);
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
