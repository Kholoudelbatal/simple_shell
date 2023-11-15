#include "shell.h"

/**
 * _strcmp - compare two strings.
 * @s1: first string
 * @s2: second string
 *
 * Return: 1 if true, 0 if false.
 */
int _strcmp(const char *s1, const char *s2)
{
	int i;

	if (_strlen(s1) != _strlen(s2))
		return (-1);
	while (*s1)
	{
		for (i = 0; s1[i] != '\0'; i++)
			if (s1[i] != s2[i])
			{
				break;
				return (-1);
			}
		s1++;
		s2++;
		i = s1[i] - s2[i];
	}

	return (i);
}


/**
 * _strcat - concatenates two strings
 * @dest: destination string
 * @src: source string
 *
 * Return: pointer to the resulting string dest
 */
char *_strcat(char *dest, const char *src)
{
	int dest_len = 0;
	int i;


	while (dest[dest_len])
		dest_len++;

	while (*src)

		for (i = 0; src[i]; i++)
			dest[dest_len++] = src[i++];


	return (dest);
}

/**
 * _strcpy - function that copies a string.
 * @dest: destination string
 * @src: source string
 *
 * Return: pointer to the resulting string dest
 */
char *_strcpy(char *dest, const char *src)
{
	int i = 0;

	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}

	dest[i] = '\0';

	return (dest);
}


/**
 * _strlen - function that returns the length of a string.
 *
 * @s: string
 * Return: return length
 */
int _strlen(const char *s)
{
	int length = 0;

	while (s[length] != '\0')
		length++;

	return (length);
}

/**
 * _strdup - create a copy of string
 * @s: string to be copied
 *
 * Return: string copied
 */

char *_strdup(const char *s)
{
	int i, len;
	char *dest;

	len = _strlen(s);
	dest = malloc(sizeof(char *) * (len + 1));

	if (s == NULL)
	{
		free(dest);
		return (NULL);
	}
	while (s[len])
	{
		len++;

	if (dest != NULL)
	{
		for (i = 0; s[i] != '\0'; i++)
		{
			dest[i] = s[i];
		}
	}
	dest[i] = '\0';
	}

	return (dest);
}
