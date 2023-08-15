#include "main.h"

/**
 * _exec - executes the program
 * @fullpath: the full path of the command
*/

void _exec(char *fullpath)
{
    pid_t child_pid;
    char *args[2];
    int status;

    child_pid = fork();
    if (child_pid == -1)
    {
        perror("fork");
        exit(EXIT_FAILURE);
    }
    else if (child_pid == 0)
    {
        args[0] = fullpath;
        args[1] = NULL;
        execve(fullpath, args, environ);
        perror("execve");
        exit(EXIT_FAILURE);
    }
    else
    {
        waitpid(child_pid, &status, 0);
    }
    free (fullpath);
}