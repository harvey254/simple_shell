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
		args[0] = command;
		args[1] = NULL;
		execve(command, args, environ);
		perror("execve");
		exit(EXIT_FAILURE);
	}
	else
	{
		wait(NULL);
	}
}
