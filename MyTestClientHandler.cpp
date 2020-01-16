
// Created by daniels on 11/01/2020.


#include <cstring>
#include <algorithm>
#include "MyTestClientHandler.h"

MyTestClientHandler::MyTestClientHandler(CacheManager<string,string> *c, Solver<string,string> *s) {
  this->cache_manager = c;
  this->solver = s;
}
void MyTestClientHandler::handleClient(int client_socket) {
  char buffer[1024] = {0};
  string str;
  string reverse_str;
  // read from client
  read(client_socket, buffer, 1024);
  str = buffer;
  string end = "end";
  while (end != str) {
    if (cache_manager->isThereSolution(str)) {
      reverse_str = cache_manager->getSolution(str);
      cout<< str <<": got it!"<<endl;
    } else {
      cout<< str <<": didnt got it!"<<endl;
      reverse_str = solver->solve(str);
      cache_manager->saveSolution(str, reverse_str);
    }
    char *c = new char[reverse_str.length() + 1];
    strcpy(c, reverse_str.c_str());
    int is_sent = send(client_socket, c, strlen(c), 0);
    char buffer2[1024] = {0};
    read(client_socket, buffer2, 1024);
    str = buffer2;
    delete (c);
    if (is_sent == -1) {
      std::cout << "Error sending message" << std::endl;
    }
  }
  close(client_socket);
}
