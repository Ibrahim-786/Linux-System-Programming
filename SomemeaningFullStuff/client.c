#include<stdio.h>
#include<string.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<stdlib.h>
#include <unistd.h>

int main(){

  int network_sock = socket(AF_INET,SOCK_STREAM,0);
  if(network_sock < 0){

    printf("socket creation error\n");
    return -1;

  }

  struct sockaddr_in serv_addr;
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_port = htons(8888);
  serv_addr.sin_addr.s_addr = INADDR_ANY;

  int connection_status = connect(network_sock, (struct sockaddr *) &serv_addr,sizeof(serv_addr));

  if(connection_status < 0){

    printf("There is an error connecting remote socket\n");
    return -1;

  }

  char* hello = "Hello from client";
  send(network_sock, hello, strlen(hello), 0);
  printf("Hello message sent\n");

  char buffer[1024] = { 0 };

  recv(network_sock, &buffer, 1024,0);
  printf("%s\n", buffer);

  close(network_sock);

  return 0;
}

