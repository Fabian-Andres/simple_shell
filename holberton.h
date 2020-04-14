#ifndef HOLBERTON
#define HOLBERTON
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
char **_get_command_and_options(char *buffer, ssize_t characters_read);
void _result_fork(char **options);
#endif
