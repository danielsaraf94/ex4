//
// Created by daniels on 11/01/2020.


#include "MyTestClientHandler.h"

MyTestClientHandler::MyTestClientHandler(CacheManager *c, Solver *s) {
  this->cache_manager = c;
  this->solver = s;
}
void MyTestClientHandler::handleClient(int client_socket) {

}
