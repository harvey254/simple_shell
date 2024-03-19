#include "shell.h"

/**
  * signal_handler - Handles the signals
  * @signal_id: The identifier of the signal to handle
  *
  * Return: No value
  */
void sig_han(int signal_id)
{
	if (signal_id == SIGINT)
		write(STDOUT_FILENO, "\n($) ", 5);
}
