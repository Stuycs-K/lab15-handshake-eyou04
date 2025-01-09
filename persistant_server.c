#include "pipe_networking.h"

void sighandler(int signo) {
    if (signo == SIGINT) {
        printf("\nServer shutting down. Removing WKP.\n");
        remove(WKP);
        exit(0);
    }
}

int main() {
    printf("In the presistant server\n");
    int to_client;
    int from_client;
    signal(SIGINT, sighandler);
    while (1) {
        printf("Waiting for a client\n");
        from_client = server_handshake( &to_client );
        printf("Connected to a client \n");

        char buffer[BUFFER_SIZE];
        int bytes;
        while (bytes = read(from_client, buffer, sizeof(buffer))) {
            printf("bytes : %d", bytes);
            write(to_client, buffer, sizeof(buffer));
        }

        printf("Handshake done!\n");
        close(from_client);
        close(to_client);
    }
}
