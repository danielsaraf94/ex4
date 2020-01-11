//
// Created by daniels on 11/01/2020.
//

#ifndef EX4_5__MYTESTCLIENTHANDLER_H_
#define EX4_5__MYTESTCLIENTHANDLER_H_
#include "ClientHandler.h"
#include "CacheManager.h"
#include "Solver.h"
class MyTestClientHandler : public ClientHandler {
  CacheManager *cache_manager;
  Solver *solver;
 public:
  MyTestClientHandler(CacheManager *, Solver *);
  void handleClient(InputSteam*,OutputSteam*;
};

#endif //EX4_5__MYTESTCLIENTHANDLER_H_
