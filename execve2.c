#include "shell.h"

void execute_cmd1(char *commands)
{
    char *cmd;
    char **args;
    char cmd_path[256];
    char **env_var;
    int status;
    pid_t pid;

    if (commands == NULL || strspn(commands, " \t\n") == strlen(commands))
        return;

    cmd = strtok(commands, "\n");

    while (cmd != NULL)
    {
	    args = malloc(MAX_ARGS * sizeof(char *));
            if (args == NULL)
            {
                perror("malloc");
                exit(EXIT_FAILURE);
            }


        if (strcmp(cmd, "env") == 0)
        {
            env_var = environ;
            while (*env_var != NULL)
            {
                printf("%s\n", *env_var);
                env_var++;
            }
        }
        else
        {
		parse_cmd(cmd, args);

            if (strchr(args[0], '/') == NULL)
            {
                while (command_path(args[0], cmd_path, sizeof(cmd_path)) == -1)
                    continue;
            }
            else
            {
                snprintf(cmd_path, sizeof(cmd_path), "/%s", args[0]);
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

            free(args);
        }

       	cmd = strtok(NULL, "\n");
    }
}

