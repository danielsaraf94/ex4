//
// Created by shlomo on 11/01/2020.
//

#ifndef EX4__SOLVER_H_
#define EX4__SOLVER_H_
#include "Solution.h"
#include "Problem.h"
class Solver {
 public:
 Solver(){};
 virtual &Solution solve(&Problem)=0;
};

#endif //EX4__SOLVER_H_
