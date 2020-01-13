//
// Created by daniels on 12/01/2020.
//

#ifndef EX4_5__STATEPRIORITYQUEUE_H_
#define EX4_5__STATEPRIORITYQUEUE_H_
#include "State.h"
#include "StateComperator.h"
#include <bits/stdc++.h>
#include "queue"
#include "vector"
using namespace std;
template<typename T>
class StatePriorityQueue {
//  priority_queue <int, vector<State<T>>, greater<double>> pq;
  vector<State<T>> pq;
  int binarySearch(double cost, int size, int location) {
    if (size == 1) {
      if (cost < pq[location].getCost) {
        return location;
      } else {
        return location + 1;
      }
    }
    int newSize = size / 2;
    if (cost < pq[location + newSize].getCost) {
      return binarySearch(cost, newSize, location);
    } else {
      return binarySearch(cost, size - newSize, location + newSize);
    }
  }
 public:
  int contain(State<T> s) {
    int i;
    for (i = 0; i < pq.size(); i++) {
      if (s.getState() == pq[i].getState()) {
        return i;
      }
    }
    return -1;
  }
  void remove(State<T> s) {
    int i = contain(s);
    if (i == -1) {
      throw "The state does not exist";
    }
    pq.erase(pq.begin() + i);
  }
  double getStateCost(State<T> s) {
    int i = contain(s);
    if (i == -1) {
      throw "The state does not exist";
    }
    return this->pq[i].getCost();
  }
  State<T> poll() {
    if (pq.size() == 0) {
      throw "The queue is empty";
    }
    State<T> s = pq[0];
    pq.erase(pq.begin());
    return s;
  }
  void push(State<T> s) {
    int i = binarySearch(s.getCost(), pq.size(), 0);
    pq.insert(pq.begin() + i);
  }
  int GetCount() const {
    return pq.size();
  }
  bool isEmpty() { return pq.empty(); }
};
#endif //EX4_5__STATEPRIORITYQUEUE_H_
