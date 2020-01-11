//
// Created by daniels on 11/01/2020.
//

#ifndef EX4_5__MYSERIALSERVER_H_
#define EX4_5__MYSERIALSERVER_H_
#include "ServerSide.h"
#include <sys/socket.h>
#include <string>
#include <iostream>
#include <netinet/in.h>
#include <unistd.h>
#include <chrono>
#include <thread>
using namespace std;
class MySerialServer : public server_side::Server {
  int socketfd;
 public:
  void open(int, ClientHandler *);
  void stop();
  static void start(int, sockaddr_in, ClientHandler *);
};

#endif //EX4_5__MYSERIALSERVER_H_
