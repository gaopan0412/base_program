/*
* resusg2.c -getting resource usage  with getrusage
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/resource.h>
#include <time.h>
#include <unistd.h>

void err_quit(char *);
void doit(char*, long);

int main(void)
{
   struct rusage usage;
   
   /*redirect output to prevent screen clutter*/
  system("grep the /usr/doc/*/* > /dev/null 2 > /dev/null");
 
  /*get the resource structure fot the parent*/
  



}
