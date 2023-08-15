#include "main.h"

/**
 * _eof - Case: EOF input or type "exit"
 * @characters : main getline return
 * @command: input
 * @not_found : error int
 * @status: status variable, int
 */

void _eof(int characters, char *command, int not_found, int status)
{
	if ((characters == -1) || (strcmp(command, "exit\n") == 0))
	{
		free(command);
		if (not_found != 0)
			exit(not_found);
		exit(WEXITSTATUS(status));
	}
}
