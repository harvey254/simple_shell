#include "shell.h"

/**
  * rm_line - Removes a new line character from string
  * @str: The string
  *
  * Return: The string without a new line character
  */
char *rm_line(char *str)
{
	int i = 0;

	while (str[i])
	{
		if (str[i] == '\n')
			str[i] = '\0';
		i++;
	}

	return (str);
}
