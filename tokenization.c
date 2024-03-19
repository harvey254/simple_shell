#include "shell.h"
/**
 * parse_cmd - tokenize command inputs
 * @cmd: command
 * @args: string of arguments
 * Return: number of tokenized arguments
 */
char **parse_cmd(char *cmd, char *delim, int len)
{
	int i = 0;
	char *token = NULL;
	char **tokens = NULL;
	char *temp = NULL;

	tokens = malloc(sizeof(char *) * (len +1));
	if (!tokens)
		return (NULL);

	cmd = rm_line(cmd);
	temp = strdup(cmd);
	token = strtok(temp, delim);

	while (token)
	{
		tokens[i] = strdup(token);
		token = strtok(NULL, delim);
		i++;
	}

	tokens[i] = NULL;
	free(temp);
	return (tokens);
}
