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
    signal(SIGINT, sighandler);
    while (1) {
        printf("Setting up WKP and waiting for a client\n");
        from_client = server_setup();
        printf("Connected to a client \n");

        printf("Forking Subserver\n");
        pid_t pid = fork();
        if (pid == 0) {
            //subserver process
            server_handshake_half(to_client, from_client);
        } else if (pid > 0) {
            //parent process
            close(from_client);
            close(to_client);
        }
    }   
}
