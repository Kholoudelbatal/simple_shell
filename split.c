#include "shell.h"

/**
 * split_string - split string into tokens using del
 * @buffer: the string to be splitted
 * @del: delimeter used to tokenize
 *
 * Return: return tokens.
 */
char **split_string(char *buffer, char *del)
{
	char *token;
	char **tokens;
	int i = 0, y = 0;

	if (!buffer)
		return (NULL);

	while (token)
	{
		y++;
		token = strtok(NULL, del);
	}

	tokens = malloc(sizeof(char *) * (y + 1));
	if (!tokens)
	{
		free(buffer);
		return (NULL);
	}

	token = strtok(buffer, del);
	while (token)
	{
		tokens[i] = token;
		token = strtok(NULL, del);
		i++;
	}
	free(buffer), buffer = NULL;
	tokens[i] = NULL;
	return (tokens);
}

