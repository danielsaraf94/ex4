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
  int count=0;
  priority_queue<State<T>, vector<State<T>>, StateComperator<T> > pq;
 public:
  State<T> poll() {
    State<T> return_state = pq.top();
    pq.pop();
    count--;
    return return_state;
  }
  void push(State<T> s) {
    count++;
    pq.push(s);
  }
  int GetCount() const {
    return count;
  }
  bool isEmpty() { return count == 0; }
};
#endif //EX4_5__STATEPRIORITYQUEUE_H_
