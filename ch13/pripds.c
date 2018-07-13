/*
*pripds.c - print pid and ppid
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
    printf("pid = %d\n", getpid());
    printf("ppid = %d\n", getppid());
   
    exit(EXIT_SUCCESS);
}
