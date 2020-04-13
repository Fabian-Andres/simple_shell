#include "holberton.h"


char **_get_command_and_options(char *buffer, ssize_t characters_read)
{
	char **flag;
	int i = 0;

	char *token = strtok(buffer, " ");
	flag = malloc(sizeof(char *));
	*flag = malloc(sizeof(char) * characters_read);
	if (!flag)
	{
		free(flag);
		exit(EXIT_FAILURE);
	}
	while (token != NULL)
	{
		flag[i] = token;
		token = strtok(NULL, " ");
		i++;
		
	}
		
	flag[i] = NULL;
	flag[i - 1] = strtok(flag[i - 1], "\n");

	return(flag);
}