#include "shell.h"

/**
 * read_line - read input from user to buffer
 *
 * Return: user input buffer
 */
char *read_line(void)
{
	char *buffer = NULL;
	size_t buffer_size = 0;
	int char_num;

	printf("%s", PROMPT);
	char_num = getline(&buffer, &buffer_size, stdin);
	if (char_num == -1)
	{
		free(array);
		exit(1);
	}

	return (buffer);
}
