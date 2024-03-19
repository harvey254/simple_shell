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
char *_getenv(const char *identity);
char *rm_line(char *str);
void sig_han(int signal_id);
int command_path(const char *command, char *path, size_t buffer_size);
void execute_cmd4(char *command);
extern char **environ;
char **parse_cmd(char *cmd, char *delim, int len);
void myshell_prompt(void);
int exit_shell(char *cmd);
void print_env(void);
int check_env(char *cmd);
char* custom_getline(void);
void execute_command(char *command);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
void assign_lineptr(char **lineptr, size_t *n, char *buffer, size_t b);
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);






#endif
