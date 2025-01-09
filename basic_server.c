#include "pipe_networking.h"

int main() {
  int to_client;
  int from_client;

  from_client = server_handshake( &to_client );
  printf("from_client = %d\n", from_client);
  if (from_client > 0) {
    char buffer[256];
    int bytes = read(from_client, buffer, sizeof(buffer));
    if (bytes > 0) {
        buffer[bytes] = '\0';
        printf("Server received: %s\n", buffer);
    } else {
        printf("No data received or read failed.\n");
    }
  }
}
