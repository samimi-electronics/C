#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <unistd.h>

#define SERVER_PORT 9002

int main(void)
{
	/* Creating the socket */
	int network_socket = socket(AF_INET, SOCK_STREAM, 0);

	/* Specifying the address of the socket */
	struct sockaddr_in server_address;
	server_address.sin_family = AF_INET;
	server_address.sin_port = htons(SERVER_PORT);
	server_address.sin_addr.s_addr = INADDR_ANY;

	int con_status = connect(network_socket, (struct sockaddr *) &server_address, sizeof(server_address));
	
	/* Check for error with the connection */
	if(con_status == -1)
	{
		printf("There was an error making a connection to the remote server\n\n");
	}
	
	/* Receive data from the remote server */
	char server_response[256];
	recv(network_socket, &server_response, sizeof(server_response), 0);

	/* Print the recieved data */
	printf("The server sent the data: %s\n", server_response);
	
	/* Close the socket */	
	close(network_socket);

	return 0;
}
