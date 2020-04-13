#include "holberton.h"


char **_get_command_and_options(char *buffer, ssize_t characters)
{
	char **options;
	int i = 0;

	char *token = strtok(buffer, " ");
	options = malloc(sizeof(char *));
	*options = malloc(sizeof(char) * characters);
	if (!options)
	{
		free(options);
		exit(EXIT_FAILURE);
	}
	while (token != NULL)
	{
		options[i] = token;
		token = strtok(NULL, " ");
		i++;
		
	}
		
	options[i] = NULL;
	options[i - 1] = strtok(options[i - 1], "\n");

	return(options);
}