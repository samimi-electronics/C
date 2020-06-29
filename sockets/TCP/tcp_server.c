#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

#define SERVER_PORT 9002

int main(void)
{
	char server_message[256] = "You have reached the server!";

	/* create server socket */
	int server_socket = socket(AF_INET, SOCK_STREAM, 0);
	
	/* define address structure */
	struct sockaddr_in server_address;
	server_address.sin_family = AF_INET;
	server_address.sin_port = htons(SERVER_PORT);
	server_address.sin_addr.s_addr = INADDR_ANY;

	/* bind the socket to our specified IP and port */
	bind(server_socket, (struct sockaddr*) &server_address, sizeof(server_address));

	/* listen for connections */	
	listen(server_socket, 5);

	int client_socket = accept(server_socket, NULL, NULL);

	/* send data to the client */
	send(client_socket, server_message, sizeof(server_message), 0);

	/* close the socket */
	close(server_socket);

	return 0;
}
