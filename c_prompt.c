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
	int i, k, status;
	size_t	n = 0;
	ssize_t nchar_read;
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
			i = 0;
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
			}
			else
				wait(&status);
	}
}

