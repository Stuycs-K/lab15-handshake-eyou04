#include "pipe_networking.h"

int main() {

  int to_server;
  int from_server;

  from_server = client_handshake( &to_server );
  printf("to_server = %d\n", to_server);
  char ack[] = "CHECK";
  int bytes = write(to_server, ack, sizeof(ack));
  if (bytes > 0) {
      printf("Mesage sent: %s\n", ack);
  } else {
      printf("No data sent.\n");
  }
}
