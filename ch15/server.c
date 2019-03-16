/*
* File: server.c
* By : gaopan
* Date:2019-3-16
* -----------------
* Brif: this file for implement of service
*
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <unistd.h>

int main(void)
{
	int server_sockfd, client_sockfd;
	int server_len, client_len;
	struct sockaddr_un server_address;
	struct sockaddr_un client_address;
	
	unlink("server_socket");
	/*create a new socket*/
	server_sockfd = socket(AF_UNIX, SOCK_STREAM, 0);
	server_address.sun_family = AF_UNIX;
	strcpy(server_address.sun_path, "server_socket");
	server_len = sizeof(server_address);
	/*bind for init socket*/
	bind(server_sockfd, (struct sockaddr*)&server_address, server_len);
	/*listen port*/
	listen(server_sockfd, 5);
	
	while (1) {
		char ch;
		printf("server waiting\n");
		client_len = sizeof(client_address);
		/*accept connection of client*/
		client_sockfd = accept(server_sockfd, (struct sockaddr*)&client_address, (socklen_t*)&client_len);
		read(client_sockfd, &ch, 1);
		ch++;
		write(client_sockfd, &ch, 2);
		close(client_sockfd);
	}
}
