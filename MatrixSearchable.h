//
// Created by shlomo on 14/01/2020.
//

#ifndef EX4__MATRIXSEARCHABLE_H_
#define EX4__MATRIXSEARCHABLE_H_
#include "Searchable.h"
class MatrixSearchable:public Searchable<int> {
 public:
  State<int>* getInitialState();
  bool isGoalState(State<int>* s);
  list<State<int>*> getAllPossibleStates(State<int>* s);
};

#endif //EX4__MATRIXSEARCHABLE_H_
