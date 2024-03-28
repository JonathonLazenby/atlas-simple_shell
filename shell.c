#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

#define MAX_COMMAND_LENGTH 100

void display_prompt(void)
{
	printf("$ ");
	fflush(stdout);
}

int main(void)
{
	char command[MAX_COMMAND_LENGTH];
	pid_t pid;
	while (1)
	{
		if (isatty(STDIN_FILENO))
		{
		
		display_prompt();
		}

		if (fgets(command, MAX_COMMAND_LENGTH, stdin) == NULL)
		{
			if (feof(stdin))
			{
				printf("\n");
				exit(EXIT_SUCCESS);
			}
		}
		command[strcspn(command, " \n")] = '\0';
		pid = fork();
		if (pid < 0)
		{
			perror("fork");
			exit(EXIT_FAILURE);
		}
		else if (pid == 0)
        	{
            		execlp(command, command, NULL);
			fprintf(stderr, "Command '%s' not found\n", command);
			exit(EXIT_FAILURE);
		}
		else
		{
		int status;
		waitpid(pid, &status, 0);
		}
	}
	return 0;
}
