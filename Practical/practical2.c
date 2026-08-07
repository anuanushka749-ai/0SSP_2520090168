#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
char command[100];
pid_t pid;
printf("Enter a linux command");
scanf("%99s",command);

pid=fork();
 if(pid<0)
{
perror("Fork failed");
return 1;
}
else if (pid==0)
{
        // Child process
        printf("\n----- Child Process -----\n");
        printf("Child PID  : %d\n", getpid());
        printf("Parent PID : %d\n", getppid());
        printf("Executing command: %s\n\n", command);

        // Execute the command
        execlp(command, command, NULL);

        // Executes only if exec() fails
        perror("Execution failed");
        exit(1);
    }
{
        // Parent process
        printf("\n----- Parent Process -----\n");
        printf("Parent PID : %d\n", getpid());
        printf("Child PID  : %d\n", pid);

        // Wait for child to complete
        wait(NULL);

        printf("\nChild process completed successfully.\n");
    }

    return 0;
}
