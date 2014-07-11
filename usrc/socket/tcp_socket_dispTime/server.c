#include <stdio.h>
#include <unistd.h>		/* close(), sleep() */
#include <sys/socket.h>		/* socket(), bind(), listen(), accept */
#include <time.h>		/* time(), ctime() */
#include <netinet/in.h>		/* struct sockaddr_in */
#include <string.h>		/* memset(), strlen() */

int main(int argc,char *argv[])
{
        struct sockaddr_in serv_addr;
        int sockfd = 0, connfd = 0;

	time_t ticks;
        char sendbuff[1000];

        sockfd = socket(AF_INET, SOCK_STREAM, 0);

        memset(sendbuff, '0', sizeof(sendbuff));
        memset(&serv_addr, '0', sizeof(serv_addr));

        serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
        serv_addr.sin_port = htons(5000);

	bind(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr));
	
	listen(sockfd, 10);
	
	while(1) {
		connfd = accept(sockfd, (struct sockaddr*)NULL, NULL);
		
		ticks = time(NULL);
		snprintf(sendbuff, sizeof(sendbuff), "%.24s\r\n", ctime(&ticks));
	
		write(connfd, sendbuff, strlen(sendbuff));
		close(connfd);
		sleep(1);
	}
	
	close(sockfd);	
}

