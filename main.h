#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void eof(int nread, char *command, int not_found, int status);
/*int exitaux(char **commandaux, int not_found, int status);*/

#endif