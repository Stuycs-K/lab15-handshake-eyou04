all: client server

client: basic_client.o pipe_networking.o
	gcc -o client basic_client.o pipe_networking.o

server: persistant_server.o pipe_networking.o
	gcc -o server persistant_server.o pipe_networking.o

basic_client.o: basic_client.c pipe_networking.h
	gcc -c basic_client.c

basic_server.o: basic_server.c pipe_networking.h
	gcc -c basic_server.c

pipe_networking.o: pipe_networking.c pipe_networking.h
	gcc -c pipe_networking.c

persistant_server.o: persistant_server.c pipe_networking.h
	gcc -c persistant_server.c

# compile_persistant: persistant_server.o
# 	gcc -o persistant_server.o

clean:
	rm *.o mario client server
	rm *~
