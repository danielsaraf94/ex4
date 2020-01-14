//
// Created by shlomo on 14/01/2020.
//

#ifndef EX4__MATRIXSEARCHABLE_H_
#define EX4__MATRIXSEARCHABLE_H_
#include "Searchable.h"
#include "Point.h"
#include "list"
#include "MatrixProblem.h"
class MatrixSearchable:public Searchable<Point> {
  MatrixProblem* matrix_problem;
 public:
  MatrixSearchable(MatrixProblem*);
  State<Point>* getInitialState();
  bool isGoalState(State<Point>* s);
  list<State<Point>*> getAllPossibleStates(State<Point>* s);
};

#endif //EX4__MATRIXSEARCHABLE_H_
