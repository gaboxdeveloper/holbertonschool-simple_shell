#include "main.h"

/**
 * main - Main loop with the prompt
 * @argc: Argument count
 * @argv: Argument vector
 * Return: 0
*/

int main(int argc, char *argv[])
{
    char *command = NULL; char *full_path = NULL;
    size_t len = 1024;
    ssize_t nread;/*Numero de bytes leidos de la linea, EOF es -1*/
    int not_found = 0; int status_p = 1;
    int isat = isatty(STDIN_FILENO); (void)argc; (void)argv;

    while (1)
    {
        if (isat == 1)
            printf("Cisnotfun$ ");
        command = malloc(len);
        if (command == NULL)
            return (-1);
        nread = getline(&command, &len, stdin);
        _eof(nread, command, not_found, status_p);
        /*Elimiar el caracter de salto de linea para mejor manejo*/
        if (nread > 0 && command[nread - 1] == '\n')
        {
            command[nread - 1] = '\0';
        }
        full_path = _which(command);
        if (full_path != NULL)
        {
            _exec(full_path);
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