/* Socket programming for client.c - This works as chat application */

#include <stdio.h>
#include <sys/socket.h>	/* AF_INET, socket(), bind(), accept(), connect() */
#include <netinet/in.h>	/* struct sockaddr_in, struct sin_addr.s_addr */
#include <netdb.h>	/* gethostbyname() */ 
#include <stdlib.h> 	/* exit() */
#include <string.h>	/* memset(), bzero(), bcopy() */ 


int main(int argc, char *argv[])
{
	int sockfd, portno, n;
	char buffer[256];

	struct sockaddr_in serv_addr;
	struct hostent *server;

	if (argc < 3) {
		fprintf(stderr," USAGE :- %s hostname port\n", argv[0]);
		exit(0);
	}

	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockfd < 0) 
		printf("ERROR opening socket");

	portno = atoi(argv[2]);
	server = gethostbyname(argv[1]);
	if (server == NULL) {
		fprintf(stderr,"ERROR, no such host\n");
		exit(0);
	}

	bzero((char *) &serv_addr, sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
	serv_addr.sin_port = htons(portno);

	if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) 
		printf("ERROR connecting");

	bzero(buffer,256);
	while(1) {
		printf("Please enter the message: ");
		fgets(buffer,255,stdin);
		n = write(sockfd,buffer,strlen(buffer));
		if (n < 0) 
			printf("ERROR writing to socket");
		bzero(buffer,256);

		n = read(sockfd,buffer,255);
		if (n < 0) 
			printf("ERROR reading from socket");
		printf("Server message: %s\n",buffer);
		bzero(buffer,256);
	}
	return 0;
}
