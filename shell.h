#ifndef SHELL_H
#define SHELL_H
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_ARGS 64
#define MAX_PATH_LENGTH 1024
#define MAX_COMMAND_LENGTH 256

extern char **environ;
void myshell_prompt(void);
int parse_cmd(char *cmd, char *args[]);
int exit_shell(char *cmd);
void print_env(void);
int check_env(char *cmd);
char* custom_getline(void);
void execute_command(char *command);
int command_path(const char *command, char *full_path, size_t size);
void exec_command(char *command, char *args[]);
void execute_cmd(char *command);
void execute_cmd1(char *command); 
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
void assign_lineptr(char **lineptr, size_t *n, char *buffer, size_t b);
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);







#endif
