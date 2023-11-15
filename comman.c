#include "shell.h"

/**
 * get_command - match the command with the path
 * @command: command to be matched
 *
 * return: the correct command
 */
char *get_command(char *command)
{
	char *path = _getenv("PATH");
	char *token;
	char *cmd_full;
	struct stat st;
	int i;

	token = strtok(path, ":");

	for (i = 0; command[i]; i++)
	{
		if (command[i] == '/')
		{
		
			if (stat(command, &st) == 0)
				return (_strdup(command));

			return (NULL);
		}
	}

	if (!path)
		return (NULL);

	while(token)
	{
		cmd_full = malloc(_strlen(token) + _strlen(command) + 2);
		if (cmd_full)
		{
			_strcpy(cmd_full, token);
			_strcat(cmd_full, "/");
			_strcat(cmd_full, command);
		if (stat(cmd_full, &st) == 0)
		{
			free(path);
			return(cmd_full);
		}
		free(cmd_full);
		token = strtok(NULL, ":");
		}
	}
	return (NULL);
}


/**
 * _strtok - tokenizing the string
 * @str: string input by user
 * @del: delimeter
 * Return: 0 on success
 */

char *_strtok(char *str, char *delim)
{
	char *token;

	delim = " ";
	token = strtok(str, delim);
	printf("%s", token);

	return (0);
}


