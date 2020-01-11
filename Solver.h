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
class Solver {
 public:
  virtual string solve(string) = 0;
};

#endif //EX4__SOLVER_H_
