#include "pipe_networking.h"

int main() {

  int to_server;
  int from_server;

  from_server = client_handshake( &to_server );
  char ack[] = "CHECK";
  int bytes = write(to_server, ack, sizeof(ack));
  printf("bytes written : %d\n", bytes);
}
