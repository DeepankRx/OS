#include <stdlib.h>
#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
int main()
{
    int child_pid = fork();
    if (child_pid > 0)
    {
        printf("Before sleep\n");
        wait();
        sleep(5);
        printf("In parent process\n");
    }
    else
    {
        printf("In child process\n");
        exit(0);
    }
    return 0;
}
