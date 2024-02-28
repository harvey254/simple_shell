#include "shell.h"
/**
 * execute_command - executes commands
 * @command: command
 * Return no value
 */
void execute_cmd(char *command)
{
	char *args[2];
	char cmd_path[256];
	char **env_var;
	int status;
	pid_t pid;

	if (command == NULL || strspn(command, "\t\n") == strlen(command))
		return;
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
	if  (strchr(args[0], '/') == NULL)
	{
		while  (command_path(args[0], cmd_path, sizeof(cmd_path)) == -1)
			continue;
	}
	else
	{
		 strcpy(cmd_path, args[0]);
	}
	pid = fork();

	if (pid == -1)
	{
		perror("fork");
	}
	else if (pid == 0)
	{
		args[0] = cmd_path;
		args[1] = NULL;
		execve(cmd_path, args, environ);
		perror("execve");
		exit(EXIT_FAILURE);
	}
	else
	{
		waitpid(pid, &status, 0);
	}
	args[0] = strtok(NULL, " ");
}
