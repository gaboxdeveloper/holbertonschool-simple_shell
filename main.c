#include "main.h"

/**
 * check_eof - Case: EOF input or type "exit"
 * @characters : main getline return
 * @command: input
 * @not_found : error int
 * @status: status variable, int
 */

void check_eof(int characters, char *command, int not_found, int status)
{
	if ((characters == -1) || (strcmp(command, "exit\n") == 0))
	{
		free(command);
		if (not_found != 0)
			exit(not_found);
		exit(WEXITSTATUS(status));
	}
}

int main(void)
{
    char *command = NULL; char *full_path = NULL;
    size_t len = 1024;/*Variable para el tamaño de la linea*/
    ssize_t nread;/*Numero de bytes leidos de la linea, EOF es -1*/
    pid_t child_pid;/*ID del proceso hijo*/
    int status, not_found = 0; int status_p = 1;
    int isat = isatty(STDIN_FILENO); char *args[2];

    while (1)
    {
        if (isat == 1)
            printf("Cisnotfun$ ");
        command = malloc(len);
        if (command == NULL)
            return (-1);
        nread = getline(&command, &len, stdin);
        check_eof(nread, command, not_found, status_p);
        /*Elimiar el caracter de salto de linea para mejor manejo*/
        if (nread > 0 && command[nread - 1] == '\n')
        {
            command[nread - 1] = '\0';
        }
        full_path = _which(command);
        if (full_path != NULL)
        {
            child_pid = fork();
            if (child_pid == -1)
            {
                perror("fork");
                exit(EXIT_FAILURE);
            }
            else if (child_pid == 0)
            {
                args[0] = full_path;
                args[1] = NULL;
                execve(full_path, args, environ);
                perror("execve");
                exit(EXIT_FAILURE);
            }
            else
            {
                waitpid(child_pid, &status, 0);
            }
            free (full_path);
        }
        else
        {
            printf("Command not found.\n");
        }
        free (command);
    }
    free (command);
    return (0);
}