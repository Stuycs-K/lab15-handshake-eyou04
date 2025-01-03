#include "pipe_networking.h"
//UPSTREAM = to the server / from the client
//DOWNSTREAM = to the client / from the server
/*=========================
  server_setup

  creates the WKP and opens it, waiting for a  connection.
  removes the WKP once a connection has been made

  returns the file descriptor for the upstream pipe.
  =========================*/
int server_setup() {
  printf("Setting Server up\n");
  int from_client = 0;
  if (mkfifo(WKP, 0666) == -1) {
    perror("Named Pipe Error");
    exit(1);
  }
  
  int WKP_error = open(WKP, O_RDWR);
  if (WKP_error == -1) {
      perror("wkp open error");
      exit(1);
  }

  remove(WKP);
  printf("Setting Server up done\n");
  return from_client;
}

/*=========================
  server_handshake 
  args: int * to_client

  Performs the server side pipe 3 way handshake.
  Sets *to_client to the file descriptor to the downstream pipe (Client's private pipe).

  returns the file descriptor for the upstream pipe (see server setup).
  =========================*/
int server_handshake(int *to_client) {
  int from_client;

  int WKP_error = open(WKP, O_RDWR);
  if (WKP_error == -1) {
      perror("wkp open error");
      exit(1);
  }

  char PP[64];
  read(WKP, PP, sizeof(PP));

  int PP_error = open(PP, O_RDWR);
  if (PP_error == -1) {
    perror("wkp open error");
    remove(PP);
    exit(1);
  }

  return from_client;
}


/*=========================
  client_handshake
  args: int * to_server

  Performs the client side pipe 3 way handshake.
  Sets *to_server to the file descriptor for the upstream pipe.

  returns the file descriptor for the downstream pipe.
  =========================*/
int client_handshake(int *to_server) {
  int from_server;
  char PP[64]; 
  sprintf(PP, "%d", getpid())
  if (mkfifo(PP, 0666) == -1) {
    perror("Private Pipe Error");
    exit(1);
  }

  int WKP_error = open(WKP, O_RDWR);
  if (WKP_error == -1) {
    perror("wkp open error");
    exit(1);
  }

  write(WKP, PP, sizeof(PP));

  int PP_error = open(PP, O_RDWR);
  if (PP_error == -1) {
    perror("wkp open error");
    remove(PP);
    exit(1);
  }

  return from_server;
}


/*=========================
  server_connect
  args: int from_client

  handles the subserver portion of the 3 way handshake

  returns the file descriptor for the downstream pipe.
  =========================*/
int server_connect(int from_client) {
  int to_client  = 0;
  return to_client;
}


