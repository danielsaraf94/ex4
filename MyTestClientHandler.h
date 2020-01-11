//
// Created by daniels on 11/01/2020.
//
#ifndef EX4_5__MYTESTCLIENTHANDLER_H_
#define EX4_5__MYTESTCLIENTHANDLER_H_
#include "ClientHandler.h"
#include "Solver.h"
#include "CacheManager.h"
class MyTestClientHandler : public ClientHandler{
  Solver solver;
  CacheManager cm;
 public:
  MyTestClientHandler(CacheManager,Solver);
   void handleClient(stream input,stream output){}
};

#endif //EX4_5__MYTESTCLIENTHANDLER_H_
