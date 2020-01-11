//
// Created by daniels on 11/01/2020.
//

#ifndef EX4_5__MYSERIALSERVER_H_
#define EX4_5__MYSERIALSERVER_H_
#include "ServerSide.h"
class MySerialServer : public server_side::Server {
 public:
  void open(int);
  void stop();
};

#endif //EX4_5__MYSERIALSERVER_H_
