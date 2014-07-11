#include <stdio.h>
#include <sys/socket.h>		/* socket(), bind(), listen(), accept */
#include <string.h>		/* memset() */
#include <netinet/in.h>		/* struct sockaddr_in */

int main(int argc,char *argv[])
{
	int sockfd = 0, connfd = 0, n;
	char recvbuff[1000];	
	struct sockaddr_in serv_addr;

	if (argc != 2) {
		printf("\n Usage: %s <ip of server> \n",argv[0]);
		return 1;
	}

	if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
		printf("Error in creating socket \n");
		return 1;
	}	
	
	memset(recvbuff, '0', sizeof(recvbuff));
	memset(&serv_addr, '0', sizeof(serv_addr));

	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = htons(5000);

	if(inet_pton(AF_INET, argv[1], &serv_addr.sin_addr)<=0) {
		printf("\n inet_pton error occured\n");
		return 1;
	} 

	if(connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
		printf("\n Error : Connect Failed \n");
		return 1;
	} 

	while ( (n = read(sockfd, recvbuff, sizeof(recvbuff)-1)) > 0) {
		recvbuff[n] = 0;
		if(fputs(recvbuff, stdout) == EOF)
			printf("\n Error : Fputs error\n");
	} 

	if(n < 0)
		printf("\n Read error \n");

	close(sockfd);
	return 0;
}
