#include "main.h"
#include <sys/wait.h>
/**
 * c_prompt - executes commands 
 * @av: pointer to string arrray
 * @env: pointer to environment variable
 *
 * Return: no value
 */
void c_prompt(char **av, char **env)
{
	char *input = NULL;
	char **env_p;
	int i, k, status;
	size_t	n = 0;
	ssize_t nchar_read;
	char *path = _getenv("PATH", env);
	char *path_command;
	char *command, *arg;
	pid_t child_pid;
	char *argv[] = {NULL, NULL};

	while (1)
	{
		printf("#cisfun$ ");
		nchar_read = getline(&input, &n, stdin);

		if (nchar_read == -1)
		{
			free(input);
			exit(EXIT_FAILURE);
		}

		command = strtok(input, "\n");

		if (command == NULL)
			continue;

		argv[0] = command;
		i = 1;
		while ((arg = strtok(NULL, "\n")) != NULL && i < 63)
		{
			argv[i++] = NULL;
		}

			i = 1;
			while (input[i])
			{
				if (input[i] == '\n')
					input[i] = 0;
				i++;
			}
			k = 0;
			argv[k] = strtok(input, " ");
			while (argv[k])
			{
				argv[++k] = strtok(NULL, " ");
			}

			if (strcmp(argv[0], "exit") == 0)
			{
				free(input);
				exit(EXIT_SUCCESS);
			}
			else if (strcmp(argv[0], "env") == 0)
			{
				*env_p = *env;
				while (*env_p)
				{
					printf("%s\n", *env_p);
					env_p++;
				}
			}	

			child_pid = fork();

			if (child_pid == -1)
			{
				perror("Error:");
				exit(EXIT_FAILURE);
			}

			if (child_pid == 0)
			{
				if (execve(argv[0],argv, env) == -1)
				{
					printf("%s: No such file or directory\n", av[0]);
					free(input);
					exit(EXIT_FAILURE);
				}
				if (path != NULL)
				{
					path_command = check_command_in_path(command,path);

					if (path_command != NULL)
					{
						execve(path_command, argv, env);
					}
					execvp(command, argv);
					fprintf(stderr, "%s: error",command);
					free(input);
					exit(EXIT_FAILURE);
				}
			}
			else
				wait(&status);
	}
}

