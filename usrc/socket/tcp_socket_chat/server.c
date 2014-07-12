/* Socket programming for server.c - This works as chat application */

#include <stdio.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdlib.h>		/* exit() */
#include <string.h>		/* bzero(), memset() */

int main(int argc, char *argv[])
{
	int sockfd, newsockfd, portno, clilen;
	char buffer[256], ser[256];
	struct sockaddr_in serv_addr, cli_addr;
	int n;

	if (argc < 2) {
		fprintf(stderr," USAGE :- %s port-number\n", argv[0]);
		exit(0);
	}

	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockfd < 0) 
		printf("ERROR opening socket \n");

	bzero((char *) &serv_addr, sizeof(serv_addr));
	portno = atoi(argv[1]);
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = INADDR_ANY;
	serv_addr.sin_port = htons(portno);

	if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) 
		printf("ERROR on binding");

	listen(sockfd,5);

	clilen = sizeof(cli_addr);
	newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
	if (newsockfd < 0) 
		printf("ERROR on accept");

	bzero(buffer,256);
	while(1) {
		n = read(newsockfd, buffer, 255);
		if (n < 0) 
			printf("ERROR reading from socket");
		printf("Client message: %s\n", buffer);
		bzero(buffer,256);

		printf("Please enter the message: ");
	        fgets(buffer,255,stdin);	

		n = write(newsockfd, buffer, strlen(buffer));
		if (n < 0) 
			printf("ERROR writing to socket");
		bzero(buffer,256);
	}
	return 0; 
}
