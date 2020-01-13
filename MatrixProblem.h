//
// Created by daniels on 13/01/2020.
//

#ifndef EX4_5__MATRIXPROBLEM_H_
#define EX4_5__MATRIXPROBLEM_H_
#include "Point.h"
class MatrixProblem {
  int **matrix;
  Point start;
  Point end;
 public:
  MatrixProblem(int **m, Point s, Point e) {
    this->matrix = m;
    this->start = s;
    this->end = e;
  }
};
#endif //EX4_5__MATRIXPROBLEM_H_
