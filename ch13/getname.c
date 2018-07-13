/*
*getname.c - get login names
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <pwd.h>

int main(void)
{

    char *login;
    struct passwd *pentry;
 
    /* get the  login name */
    if((login = getlogin()) == NULL){
    perror("getlogin");
    exit(EXIT_FAILURE);
    }
  
    /*get the password entry for login*/
    if((pentry = getpwnam(login)) == NULL){
    perror("getpwnam");
    exit(EXIT_FAILURE);
     }
 
     /*display the password entry*/
    printf("uest name:%s\n", pentry -> pw_name);
    printf("UID  %d\n", pentry -> pw_uid);
    printf("GID  %d\n", pentry -> pw_gid);
    printf("gecos %s\n", pentry -> pw_gecos);
    printf("home dir: %s\n", pentry -> pw_dir);

    exit(EXIT_SUCCESS);
}
