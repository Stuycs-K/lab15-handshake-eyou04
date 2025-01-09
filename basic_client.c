#include "pipe_networking.h"

int main() {

  int to_server;
  int from_server;

  from_server = client_handshake( &to_server );

  printf("Sending Message\n");
  char message[] = "HELLO!";
  write(to_server, message, sizeof(message));

  char ack[BUFFER_SIZE];
  while(read(from_server, ack, sizeof(ack))) {
    //printf("check\n");
    printf("Client message : %s\n", ack);
    write(to_server, ack, sizeof(ack));
  }

  /*
  printf("to_server = %d\n", to_server);
  char ack[] = "CHECK";
  int bytes = write(to_server, ack, sizeof(ack));
  if (bytes > 0) {
      printf("Mesage sent: %s\n", ack);
  } else {
      printf("No data sent.\n");
  }
  */
}
