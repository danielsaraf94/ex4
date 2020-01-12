//
// Created by shlomo on 12/01/2020.
//

#ifndef EX4__BFS_H_
#define EX4__BFS_H_
#include "Solution.h"
#include "set"
using namespace std;
template<typename T>
class BestFirstSearch: public ASearcher<T> {
  set closed;
 public:
  BestFirstSearch<T>():ASearcher<T>(){};
  Solution<T> search(Searchable<T>)
};

#endif //EX4__BFS_H_
