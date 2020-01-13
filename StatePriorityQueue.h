//
// Created by daniels on 12/01/2020.
//

#ifndef EX4_5__STATEPRIORITYQUEUE_H_
#define EX4_5__STATEPRIORITYQUEUE_H_
#include "State.h"
#include "StateComperator.h"
#include <bits/stdc++.h>
using namespace std;
template<typename T>
class StatePriorityQueue {
  multiset<State<T>> pq;
 public:
  bool contain(State<T> s) {
    return !(pq.find(s) == pq.end());
  }
  void remove(State<T> s) {
    auto it = pq.find(s);
    pq.erase(it);
  }
  State<T> poll() {
    State<T> return_state = *pq.begin();
    auto it = pq.begin();
    pq.erase(it);
    return return_state;
  }
  void push(State<T> s) {
    pq.insert(s);
  }
  int GetCount() const {
    return pq.size();
  }
  bool isEmpty() { return pq.empty(); }
};
#endif //EX4_5__STATEPRIORITYQUEUE_H_
