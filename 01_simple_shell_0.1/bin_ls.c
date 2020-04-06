#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

int _strcmp(char *s1, char *s2)
{
	int a;

	for (a = 0; s1[a] != 0; a++)
	{
	}
	for (a = 0; s2[a] != 0; a++)
	{
		if (s1[a] != s2[a])
		{
			return (s1[a] - s2[a]);
		}
	}
	return (0);
}


int main(void)
{
	while (1) /*true*/
	{
		char *buffer;
		size_t bufsize = 1024;
		int str_equal;

		int id;
		int status;

		buffer = (char *)malloc(bufsize * sizeof(char));
		if (buffer == NULL)
		{
			perror("Unable to allocate buffer");
			exit(1);

		}
		printf("$ ");
		/*Buffer is the scanf, bufsize is the size of buffer, stdin is the variable where the variable buffer will be save*/
		
		getline(&buffer, &bufsize, stdin);

		/*Function _strcmp compares two string*/
		str_equal = _strcmp(buffer, "/bin/ls");

		if (str_equal == 0)
		{
			/*Fork creates new process*/
			id = fork();
			if (id == 0)
			{
				char *args[] = {"ls", (char *)0};
				char *env_args[] = { (char *)0 };

				/*The execve function search a file in the path*/
				execve("/bin/ls", args, env_args); 
				exit(0);
			}
			else
			{
				/*When process parent finish, continue here*/
				if (waitpid(id, &status, 0) > 0) 
				{
					/*State child*/
				}
			}
        }    
		else
		{
			printf("./shell: No such file or directory\n");
		}	
	}
	return (0);
}
