 /*
    ** listener.c -- a datagram sockets "server" demo
http://beej.us/guide/bgnet/output/html/multipage/clientserver.html#figure2
    */

#include <stdio.h> 
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

    #define MYPORT 4950    // the port users will be connecting to

    #define MAXBUFLEN 100

    int main(void)
    {
        int sockfd;
        struct sockaddr_in my_addr;    // my address information
        struct sockaddr_in their_addr; // connector's address information
        //  int addr_len, numbytes; for g++
  			socklen_t addr_len;
  			int numbytes;
        char buf[MAXBUFLEN];

        if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) == -1) {					//1. Create a socket
            perror("socket");
            exit(1);
        }

        my_addr.sin_family = AF_INET;         // host byte order
        my_addr.sin_port = htons(MYPORT);     // short, network byte order
        my_addr.sin_addr.s_addr = INADDR_ANY; // automatically fill with my IP
        memset(&(my_addr.sin_zero), '\0', 8); // zero the rest of the struct

        if (bind(sockfd, (struct sockaddr *)&my_addr,							// 2. bind: identity a socket
                                              sizeof(struct sockaddr)) == -1) {
            perror("bind");
            exit(1);
        }
			  printf("listener: waiting to recvfrom...\n");
        addr_len = sizeof(struct sockaddr);									// 3. Communication
        if ((numbytes=recvfrom(sockfd, buf, MAXBUFLEN-1, 0,
                           (struct sockaddr *)&their_addr, &addr_len)) == -1) {
            perror("recvfrom");
            exit(1);
        }

        printf("got packet from %s\n",inet_ntoa(their_addr.sin_addr));
        printf("packet is %d bytes long\n",numbytes);
        buf[numbytes] = '\0';
        printf("packet contains \"%s\"\n",buf);

        close(sockfd);														// 4. Close socket

        return 0;
    } 

