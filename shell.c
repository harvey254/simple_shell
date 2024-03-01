#include "shell.h"
/**
 * main - entry point
 *
 * Return: Sucess(0), (-1) oterwise
 */
int main(void)
{
	char command[MAX_COMMAND_LENGTH];

	if (isatty(fileno(stdin)))
	{
		while (1)
		{
			printf("$ ");
			if (fgets(command, sizeof(command), stdin) == NULL)
				break;
			if (command[strlen(command) - 1] == '\n')
			{
				command[strlen(command) - 1] = '\0';
				execute_command(command);
			}
		}
	}
	else
	{
		while (fgets(command, sizeof(command), stdin) != NULL)
		{
			if (command[strlen(command) - 1] == '\n')
                        {
                                command[strlen(command) - 1] = '\0';
				if (strcmp(command, "exit") == 0)
					exit(EXIT_SUCCESS);

                                execute_command(command);
			}
		}
	}

	return (0);
}
