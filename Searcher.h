//
// Created by shlomo on 12/01/2020.
//

#ifndef EX4__SEARCHER_H_
#define EX4__SEARCHER_H_
#include "Solution.h"
#include "Searchable.h"
template<typename T>
class Searcher {
 public:
  Searcher<T>() {};
  virtual Solution<T> search(Searchable<T>) = 0;
  virtual int getNumberOfNodeEvaluated() = 0;
};

#endif //EX4__SEARCHER_H_
