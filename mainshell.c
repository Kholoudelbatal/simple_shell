#include "shell.h"

/**
 * main - main shell function
 * @argc: arguments count.
 * @argv: arguments.
 * @env: a NULL terminated array of strings.
 *
 * Return: return 0 on success.
 */

int main(int argc, char **argv, char **env)
{
	(void)argc;
	(void)argv;
	char *buffer = NULL, *token, *cmd;
	size_t buffer_size = 0;
	int status, i = 0;
	char **array;
	pid_t pid;

	while (1)
	{
		printf("%s", PROMPT);
		buffer = read_line();
		array = malloc(sizeof(char *) * 1024);
		token = strtok(buffer, " \t\n");
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
				execve(cmd, array, env);
			}
			if (execve(array[0], array, env) == -1)
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

