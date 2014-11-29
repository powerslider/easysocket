#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "easysocket.h"

int main() {
    int connfd, socketfd, retval;
    char* buf = calloc(16,1);
    socketfd = create_inet_server_socket("127.0.0.1", "5000", SOCKET_TCP, SOCKET_IPv4, 0);
    if (socketfd < 0) {
        perror(0);
        exit(1);
    }

    connfd = accept_inet_client_socket(socketfd);
    if (connfd < 0) {
        perror(0);
        exit(1);
    }

    retval = read(connfd, buf, 15);
    if (retval < 0) {
        perror(0);
        exit(1);
    }

    printf("%s\n",buf);

    retval = close_inet_socket(socketfd);
    if (retval < 0) {
        perror(0);
        exit(1);
    }

    return 0;
}
