#include "shell.h"

/**
 * main - main shell function
 * Return: return 0 on success.
 */

int main()
{
	char *buffer = NULL;
	char *token, *cmd;
	size_t buffer_size = 0;
	int status, i = 0;
	int char_num;
	char **array;
	pid_t pid;

	while (1)
	{
		printf("%s", PROMPT);
		char_num = getline(&buffer, &buffer_size, stdin);
		array = malloc(sizeof(char *) * 1024);
		token = strtok(buffer, " \t\n");
		if (char_num == -1)
                {
                        free(array);
                        exit(1);
                }
		if (buffer == NULL)
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			return (status);
		}
		array = split_string(buffer, " \t\n");
		if (_strcmp(array[0], "exit") == 0)
		{
			exit(0);
		}
		while (token)
		{
			array[i] = token;
			token = strtok(NULL, " \t\n");
			i++;
		}
		array[i] = NULL;
		pid = fork();
		if (pid == 0)
		{
			cmd = get_command(array[i]);
			if (cmd)
			{
				execve(cmd, array, environ);
			}
			if (execve(array[0], array, environ) == -1)
			{
				perror("execve");
			}
			else
			{
				printf("Command not found\n");
				exit(0);
			}
		}
		else
		{
			wait(&status);
		}
	}
	return (0);
}

