#include "shell.h"

/**
 * _setenv - setting new variable
 * @name: name of var
 * @value: the value of the var
 * @overwrite: overwriting the var
 *
 * Return: 0 on success
 */
int _setenv(const char *name, const char *value, int overwrite)
{
	extern char **environ;
	int i = 0, len = 0;
	char *new_var;

	if (!name || !value)
		return (-1);
	while(environ[i])
	{
		len = _strlen(name);
		if (strncmp(environ[i], name, len) == 0)
		{
			if (overwrite)
			{
				new_var = malloc(_strlen(name) + _strlen(value) + 2);
				_strcpy(new_var, name);
				_strcat(new_var, "=");
				_strcat(new_var, value);
				environ[i] = new_var;
				return (0);
			}
			return (0);
		}
		i++;
	}
	new_var = malloc(_strlen(name) + _strlen(value) + 2);
	_strcpy(new_var, name);
	_strcat(new_var, "=");
	_strcat(new_var, value);
	environ[i] = new_var;

	environ[i + 1] = NULL;

	return (0);
}

/**
 * _getenv - get the environ path
 * @env_var: environ variable
 *
 * Return: 0 on success
 */
char *_getenv(const char *env_var)
{
	extern char **environ;
	int i = 0;
	char *key;

	while(environ[i])
	{
		key = strtok(environ[i], "=");
		if (_strcmp(key, env_var) == 0)
			return (strtok(NULL, "\n"));
		i++;
	}
	return (NULL);
}

