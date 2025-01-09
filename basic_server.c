#include "pipe_networking.h"

int main() {
  int to_client;
  int from_client;

  from_client = server_handshake( &to_client );
  char ack_knw[256];
  printf("buffer : %s\n", ack_knw);
  int bytes = read(from_client, ack_knw, sizeof(ack_knw));
  printf("bytes read : %d\n", bytes);
  printf("%s\n", ack_knw);
}
