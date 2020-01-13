//
// Created by daniels on 11/01/2020.


#ifndef EX4_5__MYTESTCLIENTHANDLER_H_
#define EX4_5__MYTESTCLIENTHANDLER_H_
#include "ClientHandler.h"
#include "CacheManager.h"
#include "Solver.h"
#include <cstring>
#include <algorithm>
#include <vector>
#include <iostream>
#include <cstdlib>
#include "MatrixProblem.h"
#include "Solution.h"
#include "State.h"
class MyClientHandler : public ClientHandler {
  CacheManager<string, string> *cache_manager;
  Solver<MatrixProblem, Solution<string>> *solver;
 public:
  MyClientHandler(CacheManager<string, string> *c, Solver<MatrixProblem, Solution<string>> *s);
  void handleClient(int);
  int getNumberOfCols(string);
};

#endif //EX4_5__MYTESTCLIENTHANDLER_H_
