#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "easysocket.h"

int main() {
    int socketfd, retval;
    char* buf = "Hello EasySocket";
    socketfd = create_inet_client_socket("127.0.0.1", "5000", SOCKET_IPv4, 0);
    printf("%d", socketfd);
    if (socketfd < 0) {
        perror(0);
        exit(1);
    }

    retval = write(socketfd, buf, 5);

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
