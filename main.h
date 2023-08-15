#ifndef MAIN_H
#define MAIN_H

#define MAX_COMMAND_LEN 100

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void check_eof(int nread, char *command, int not_found, int status);
char *_getenv(char *env);
char *_which(const char *command);
/*int exec(char *fullpath);*/

extern char **environ;

#endif