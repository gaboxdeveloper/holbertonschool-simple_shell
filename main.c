#include "main.h"

int main(void)
{
    char *command = NULL;/*Puntero para almacenar el comando ingresado*/
    size_t len = 1024;/*Variable para el tamaño de la linea*/
    ssize_t nread;/*Numero de bytes leidos de la linea, EOF es -1*/
    pid_t child_pid;/*ID del proceso hijo*/
    int status, not_found = 0; int status_p = 1;
    int isat = isatty(STDIN_FILENO);

    while (status_p == 1)
    {
        if (isat == 1)
            printf("Cisnotfun$ ");
        command = malloc(len);
        if (command == NULL)
            return (-1);
        nread = getline(&command, &len, stdin);
        eof(nread, command, not_found, status_p);
        /*Elimiar el caracter de salto de linea para mejor manejo*/
        if (nread > 0 && command[nread - 1] == '\n')
        {
            command[nread - 1] = '\0';
        }
        child_pid = fork();
        if (child_pid == -1)
        {
            perror("fork");
            exit(EXIT_FAILURE);
        }
        else if (child_pid == 0)
        {
            /*Child process*/
            char *args[] = {NULL};
            char *envp[] = {NULL};/*Variables de entorno*/
            execve(command, args, envp);/*Ejecutar el programa*/
            perror("execve");
            exit(EXIT_FAILURE);
        }
        else
        {
            /*Parent process*/
            waitpid(child_pid, &status, 0);/*Esperar a que termine el proceso hijo*/
        }
    }
    free (command);
    return (0);
}