//
// Created by daniels on 12/01/2020.
//

#ifndef EX4_5__ASEARCHER_H_
#define EX4_5__ASEARCHER_H_
#include "Searcher.h"
#include "State.h"
#include "StatePriorityQueue.h"
#include <bits/stdc++.h>

using namespace std;
template<typename T>
class ASearcher : public Searcher<T> {
 private:
  StatePriorityQueue<T> open_list;
  int evaluatedNodes;
 protected:
  void openRemove(State<T> s){
    open_list.remove(s);
  }
  bool openContaines(State<T> s){
    return open_list.contain(s);
  }
  State<T> popOpenList() {
    evaluatedNodes++;
    return open_list.poll();
  }
  void pushOpenList(State<T> s) {
    open_list.push(s);
  }
  int openListSize() {
    return open_list.GetCount();
  }
  bool isEmpty() {
    return open_list.GetCount() == 0;
  }
 public:
  ASearcher() {
    open_list = new StatePriorityQueue<T>();
    evaluatedNodes = 0;
  }
  int getNumberOfNodesEvaluated() { return evaluatedNodes; }
  virtual Solution<T> search(Searchable<T>) = 0;
};
#endif //EX4_5__ASEARCHER_H_
