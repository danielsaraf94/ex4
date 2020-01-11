//
// Created by daniels on 11/01/2020.
//

#ifndef EX4_5__CLIENTHANDLER_H_
#define EX4_5__CLIENTHANDLER_H_
#include "InputSteam.h"
#include "OutputStream.h"
class ClientHandler {
 public:
  virtual void handleClient(InputSteam*,OutputSteam*) = 0;
};
#endif //EX4_5__CLIENTHANDLER_H_
