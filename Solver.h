//
// Created by shlomo on 11/01/2020.
//

#ifndef EX4__SOLVER_H_
#define EX4__SOLVER_H_
#include <sys/socket.h>
#include <string>
#include <iostream>
#include <netinet/in.h>
#include <unistd.h>
#include <chrono>
#include <thread>
using namespace std;
template<typename P,typename S>
class Solver {
 public:
  Solver<P,S>(){};
  virtual S solve(P) = 0;
};

#endif //EX4__SOLVER_H_
