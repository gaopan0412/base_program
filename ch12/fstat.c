/*
  mstat.c - naive stat program
*/


#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc , char **agrv)
{

   struct stat buf;
   mode_t mode;
   char type[80];
  
   int fd;
   /*validate the command line*/
   if(argc != 2)
    puts("Usage:mstat {file}");

   /*open the file*/
   if((fd = open(argv[1], O_RDONLY)) < 0)
    {  
    perror("open");
    exit(EXIT_FAILURE);
    }
    
   /*get file stats*/
   if((fstat(fd, buf)) < 0)
   {
   perror("fdstat");
   exit(EXIT_FAILURE);
   }

   mode=buf.st_mode;
   printf("      FILE:%s\n", argv[1]);
   printf("     INODE:%ld\n", buf.st_ino);
   printf("    DEVICE:%d %d\n", major(buf.st_dev),
                                minor(buf.st_dev));
 
  printf("       MODE:%#O\n", mode &~(S_IFMT));
  printf("      LINKS:%d\n", buf.st_nlink);
  printf("      UID:%d\n", buf.st_uid);
  printf("      GID:%d\n", buf.st_gid);

  if(S_ISLINK(mode))
  strcpy(type, "Symbolic line");
  else if(S_ISREG(mode))
  strcpy(type, "Regular file");
  else if(S_ISDIR(mode))
  strcpy(type, "Directory");
  else if(S_ISCHR(mode))
  strcpy(type, "character device");
  :







}
