#include "pipe_networking.h"

void sighandler(int signo) {
    if (signo == SIGINT) {
        printf("\nServer shutting down. Removing WKP.\n");
        remove(WKP);
        exit(0);
    }
}

int main() {
    int to_client;
    int from_client;

    while (1) {
        from_client = server_handshake( &to_client );
        printf("Connected to a client \n");

        char buffer[BUFFER_SIZE];
        while (read(from_client, buffer, sizeof(buffer)) > 0) {
            printf("Received: %s", buffer);
            write(to_client, buffer, sizeof(buffer));
        }

        printf("Handshake done!\n");
        close(from_client);
        close(to_client);
    }
}
