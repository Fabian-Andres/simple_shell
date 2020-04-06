#include "holberton.h"

int main(void)
{
	while (1) /*true*/
	{
		char *buffer;
		size_t bufsize = 1024;
		int str_equal;

		int id;
		int status;

		int i;

		char *builtin_str[] = {
			"/bin/ls",
			"ls",
			"exit"
		};
		/*int (*builtin_func[]) (char **) = {
			&lsh_ls,
			&lsh_ls,
			&lsh_exit
		};*/

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
		for (i = 0; i < 3; i++) {
			if (_strcmp(buffer, builtin_str[i]) == 0) {
				/*return (*builtin_func[i])(args);*/
				printf("- %s, %s", builtin_str[i]);
			}
		}
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
