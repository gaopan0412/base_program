/*
*resusg1.c - get process times
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/times.h>
#include <time.h>
#include <unistd.h>

void doit(char * , clock_t);
int main(void)
{
   clock_t start, end;
   struct tms t_start, t_end;
   
   start = times(&t_start);
   /*redirect output to prevent screen clutter*/
   system("grep the /usr/doc/*/* > /dev/null 2> /dev/null");
   end = times(&t_end);
   
   doit("elapsed", end - start);
 
   puts("parent times");
   doit("\tuser cpu", t_end.tms_utime);
   doit("\tsys cpu", t_end.tms_stime);
   
   exit(EXIT_SUCCESS);
}

void doit(char *str, clock_t time)
{
    /*Get clock ticks/second*/
    long tps = sysconf(_SC_CLK_TCK);
    
    printf("%s: %6.2f secs\n", str, (float)time/tps);
}


