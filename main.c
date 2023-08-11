#include "main.h"

/*#define MAX_COMMAND_LEN 100*/

int main(void)
{
    char *command = NULL;/*Puntero para almacenar el comando ingresado*/
    size_t len = 0;/*Variable para el tamaño de la linea*/
    ssize_t nread;/*Numero de bytes leidos de la linea, EOF es -1*/
    pid_t child_pid;/*ID del proceso hijo*/
    int status;/*Estado del proceso hijo*/
    int status_p = 1;

    while (status_p == 1)
    {
        printf("Cisnotfun$ ");
        nread = getline(&command, &len, stdin);

        /*Elimiar el caracter de salto de linea para mejor manejo*/
        if (nread > 0 && command[nread - 1] == '\n')
            command[nread - 1] = '\0';

        /*Si escribimos exit o presionamos "Ctrl + D" el programa termina*/
        if ((nread == -1))
        {
            printf("\n");
            status_p = -1;
        }
        else
        {
            child_pid = fork();

            if (child_pid == -1)
            {
                perror("fork");
                exit(EXIT_FAILURE);
            }
            else if (child_pid == 0)
            {
                /*Child process*/
                /*tokenizer(command);*/
                char *args[] = {"ls"};
                char *envp[] = {NULL};/*Variables de entorno*/
                execve(command, args, envp);/*Ejecutar el programa*/
                perror("execve");
                exit(EXIT_FAILURE);
            }
            else
            {
                /*Parent process*/
                waitpid(child_pid, &status, 0);/*Esperar a que termine el proceso hijo*/
                /*if (WIFEXITED(status))
                {
                    printf("Child process exited with status %d\n", WEXITSTATUS(status));
                }
                else
                {
                    printf("Child process did not exit normally\n");
                }*/
            }
        }
    }
    free (command);
    return (0);
}