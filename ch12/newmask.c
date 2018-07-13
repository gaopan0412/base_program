/*
* newmask.c - change the umask
*/


#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>


int main(void)
{
   mode_t newmask = 0222, oldmask;
   system("touch before");
   oldmask = umask(newmask);
   printf("old umask is %#o\n", oldmask);
   printf("new umask is %#o\n", newmask);
   
   system("touch after");
   exit(EXIT_SUCCESS);
}
