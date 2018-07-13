/**
* ids.c - print real and ettective UIDS and GIDS	
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
    printf("Real user id:%d\n", getuid());
    printf("Effective uesr id:%d\n", geteuid());
    printf("Real group id:%d\n", getgid());
    printf("Effective group id:%d\n", getegid());

    exit(EXIT_SUCCESS);
}
