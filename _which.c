#include "main.h"

/**
 * _which - Function that search and return full path of a command
 * @command: input
 * Return: The full path or NULL if it fails
*/

char *_which(const char *command)
{
	char *path = _getenv("PATH");
	char *path_copy = malloc(strlen(path) + 1);
	char *token = NULL;

	strcpy(path_copy, path);
	token = strtok(path_copy, ":");
	if (access(command, X_OK) == 0)
	{
		return (strdup(command));
	}

	while (token != NULL)
	{
		char *full_path = malloc(MAX_COMMAND_LEN);

		snprintf(full_path, MAX_COMMAND_LEN, "%s/%s", token, command);
		if (access(full_path, X_OK) == 0)
		{
			free(path_copy);
			return (full_path);
		}
		token = strtok(NULL, ":");
		free(full_path);
	}
	free(path_copy);
	return (NULL);
}
