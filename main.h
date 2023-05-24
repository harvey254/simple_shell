#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <limits.h>
#include <time.h>

extern char **environ;


void c_prompt(char **av, char **env);

typedef struct builtin_c
{
	char *env;
	char *exit;
}builtin;


void printenv(void);

void exit_cmd(char **cmd, char *input);
void freebuff(char **buff);
char *_getenv(const char *name, char **env);
char *check_command_in_path(const char *command, const char *path);
char *create_full_path(const char *dir, const char *command);

char *find_path(void);

#endif
