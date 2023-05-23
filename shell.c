#include "main.h"
/**
 * main - simple shell
 * @ac: number of arguments
 * @av: pointer to an array of strings
 * @env: NULL terminating array of strings
 * Return: 0 (Always) Success
 */
int main(int ac, char **av, char **env)
{
	if (ac == 1)
		c_prompt(av, env);

	return (0);
}
