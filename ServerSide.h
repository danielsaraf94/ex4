//
// Created by daniels on 11/01/2020.
//

#ifndef EX4_5__SERVERSIDE_H_
#define EX4_5__SERVERSIDE_H_
#include "ClientHandler.h"
namespace server_side {
class Server {
 public:
  virtual void open(int,ClientHandler*) = 0;
  virtual void stop() = 0;
};
}
#endif //EX4_5__SERVERSIDE_H_
