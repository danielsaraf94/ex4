//
// Created by daniels on 11/01/2020.


#include <cstring>
#include "MyTestClientHandler.h"

MyTestClientHandler::MyTestClientHandler(CacheManager *c, Solver *s) {
  this->cache_manager = c;
  this->solver = s;
}
void MyTestClientHandler::handleClient(int client_socket) {
  char buffer[1024] = {0};
  // read from client
  read(client_socket, buffer, 1024);
  while(!strcmp("end",buffer)){
    if(cache_manager->isThereSolution(buffer)){

    }
    else{

    }
    char buffer[1024] = {0};
    read(client_socket, buffer, 1024);
  }
}
