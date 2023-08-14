#include "main.h"
/**
 * main_aux0 - Case: EOF input
 * @characters : main getline return
 * @command: input
 * @not_found : error int
 * @status: status variable, int
 */

void eof(int characters, char *command, int not_found, int status)
{
	if (characters == -1)
	{
		free(command);
		if (not_found != 0)
			exit(not_found);
		exit(WEXITSTATUS(status));
	}
}


/**
 * main_aux_exit - Handles the "exit" built it
 * @commandaux : list of arguements
 * @not_found : error int
 * @status: status variable, int
 *
 * Return: 0 if the argument is not "exit", != 0 otherwise
 */
/*int exitaux(char **commandaux, int not_found, int status)
{
	if (strcmp(commandaux[0], "exit") == 0)
	{
		free_grid(commandaux);
		if (not_found != 0)
			exit(not_found);
		exit(WEXITSTATUS(status));
	}
	return (0);
}*/