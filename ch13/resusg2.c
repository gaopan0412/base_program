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
  if ((getrusage(RUSAGE_SELF, &usage)) == -1 )
       err_quit("getrusage");
 
  puts("parent times");
  doit("\tuser CPU", usage.ru_utime.tv_sec);
  doit("\tuser CPU", usage.ru_stime.tv_sec);
  
  puts("parent memory stats");
  doit("\tminor fault", usage.ru_minflt);
  doit("\tmajor fault", usage.ru_majflt);
  doit("\tpage swaps", usage.ru_nswap);

  /*get the resource structure for the child*/
  if((getrusage(RUSAGE_CHILDREN, &usage)) == -1)
    err_quit("getrusage");
  
  puts("child times");
  doit("\tuser CPU", usage.ru_utime.tv_sec);
  doit("\tuser CPU", usage.ru_utime.tv_sec);
  
  puts("child memory stats");
  doit("\tminor faults", usage.ru_minflt);
  doit("\tmajor faults", usage.ru_majflt);
  doit("\tpage swaps", usage.ru_nswap);
  
  exit(EXIT_SUCCESS);
}

void doit(char *str, long resval)
{
   printf("%s:%ld\n", str, resval);
}

void err_quit(char *str)
{
   perror(str);
   
   exit(EXIT_SUCCESS);
}












