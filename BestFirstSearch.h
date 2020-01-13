//
// Created by shlomo on 12/01/2020.
//

#ifndef EX4__BFS_H_
#define EX4__BFS_H_
#include "Searcher.h"
#include "Solution.h"
#include "State.h"
#include "set"
#include "list"
using namespace std;
template<typename T>
class BestFirstSearch : public Searcher<T> {
  int evaluatedNodes;
  set<State<T>> closed;
  Solution<T> backTrace();
  StatePriorityQueue<T> open_list;
  State<T> popOpenList() {
    evaluatedNodes++;
    return open_list.poll();
  }
 public:
  BestFirstSearch<T>() : ASearcher<T>() {
    this->evaluatedNodes = 0;
    open_list = new StatePriorityQueue<T>();
  }
  int getNumberOfNodesEvaluated() {
    return evaluatedNodes;
  }

  Solution<T> search(Searchable<T>) {
    pushOpenList(s.getInitialState());
    while (!isEmty()) {
      State<T> n = popOpenList();
      this->closed.insert(n);
      if (s.isGoalState(n)) {
        return backTrace();
      }
      list<State<T>> successors = s.getAllPossibleStates(n);
      for (State s: successors) {
        if (!closed.count(s) && !openContaines(s)) {
          pushOpenList(s);
        } else if (openContaines(S)) {
          if (get){
            if()
          }
        }
      }
    }
  }
};

#endif //EX4__BFS_H_
