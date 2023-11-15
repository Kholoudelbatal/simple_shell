#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

#define PROMPT "$ "

int main(int argc, char **argv, char **env);
char **split_string(char *buffer, char *del);

/*strman*/
char *_strcpy(char *dest, const char *src);
char *_strcat(char *dest, const char *src);
int _strcmp(const char *s1, const char *s2);
int _strlen(const char *s);
char *_strdup(const char *s);

/*env*/
int _setenv(const char *name, const char *value, int overwrite);
char *_getenv(const char *env_var);

/*command*/
char *get_command(char *command);
char *_strtok(char *str, char *delim);
#endif

