#include "main.h"

/**
 * _getenv - Searchs the PATH environment variable on
 * the environment
 * @envr: the  environment list
 * Return: the value of PATH in string format
 */

char *_getenv(char *envr)
{
	int i, len = strlen(envr);

	for (i = 0; environ[i]; i++)
	{
		if (strncmp(envr, environ[i], len) == 0)
			return (environ[i] + len + 1);
	}
	return (NULL);
}