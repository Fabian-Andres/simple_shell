#ifndef HOLBERTON
#define HOLBERTON
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
/* _strcmp - compare two strings */
int _strcmp(char *s1, char *s2);
char **_get_command_and_options(char *buffer, ssize_t characters_read);

#endif