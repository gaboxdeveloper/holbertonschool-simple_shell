#include "main.h"

#define MAX_COMMAND_LEN 100

int main(void)
{
    char *command = NULL;/*Puntero para almacenar el comando ingresado*/
    size_t len = 0;/*Variable para el tamaño de la linea*/
    ssize_t nread;/*Numero de bytes leidos de la linea, EOF es -1*/
    pid_t child_pid;/*ID del proceso hijo*/
    int status;/*Estado del proceso hijo*/
    char *args[2]; char full_command[MAX_COMMAND_LEN];/*Argumentos para el programa*/

    while (1) {
        printf("Cisnotfun$ ");
        nread = getline(&command, &len, stdin);

        /*Elimiar el caracter de salto de linea para mejor manejo*/
        if (nread > 0 && command[nread - 1] == '\n')
            command[nread - 1] = '\0';

        /*Si escribimos exit o presionamos "Ctrl + D" el programa termina*/
        if ((strcmp(command, "exit") == 0) || (nread == -1))
        {
            printf("Exiting the shell.\n");
            break;
        }

        /*Buscar el camino completo del comando*/
        strcpy(full_command, "/bin/");
        strcat(full_command, command);

        args[0] = full_command;
        args[1] = NULL;

        child_pid = fork();

        if (child_pid == -1)
        {
            perror("fork");
            exit(EXIT_FAILURE);
        }
        else if (child_pid == 0)
        {
            /*Child process*/
            char *envp[] = {NULL};/*Variables de entorno*/
            execve(full_command, args, envp);/*Ejecutar el programa*/
            perror("execve");
            exit(EXIT_FAILURE);
        }
        else
        {
            /*Parent process*/
            waitpid(child_pid, &status, 0);/*Esperar a que termine el proceso hijo*/
            if (WIFEXITED(status))
            {
                printf("Child process exited with status %d\n", WEXITSTATUS(status));
            }
            else
            {
                printf("Child process did not exit normally\n");
            }
        }
    }
    free (command);
    return (0);
}