#include "shell.h"

/**
 * execute_command - executes commands
 * @command: command
 * Return no value
 */
void execute_cmd4(char *command) {
    char *token;
    char *whitespace_token = " \t\n";

    token = strtok(command, whitespace_token);
    while (token != NULL) {
        char *args[2];
        char cmd_path[256];
        int status;
        pid_t pid;

        if (token == NULL || strspn(token, whitespace_token) == strlen(token)) {
            token = strtok(NULL, whitespace_token);
            continue;
        }

        parse_cmd(token, args);
        if (strchr(args[0], '/') == NULL) {
            while (command_path(args[0], cmd_path, sizeof(cmd_path)) == -1)
                continue;
        } else {
            snprintf(cmd_path, sizeof(cmd_path), "%s", args[0]);
        }
        pid = fork();

        if (pid == -1) {
            perror("fork");
        } else if (pid == 0) {
            args[0] = cmd_path;
            args[1] = NULL;
            execve(cmd_path, args, environ);
            perror("execve");
            exit(EXIT_FAILURE);
        } else {
            waitpid(pid, &status, 0);
        }
        token = strtok(NULL, whitespace_token);
    }
}
