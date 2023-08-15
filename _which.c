#include "main.h"

char *_which(const char *command)
{
    char *path = _getenv("PATH");
    char *path_copy = malloc(strlen(path) + 1);
    char *token = NULL;
    char *full_path = malloc(MAX_COMMAND_LEN);
    strcpy(path_copy, path);
    token = strtok(path_copy, ":");

    while (token != NULL)
    {
        snprintf(full_path, MAX_COMMAND_LEN, "%s/%s", token, command);
        if (access(full_path, X_OK) == 0)
        {
            free(path_copy);
            return full_path;
        }
        token = strtok(NULL, ":");
    }

    free(path_copy);
    free(full_path);
    return NULL;
}