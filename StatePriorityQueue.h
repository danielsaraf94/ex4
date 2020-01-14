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
  map<T, double> costOfState;
  int binarySearch(double cost, int size, int location) {
    if (size == 0) {
      return location;
    }
    if (size == 1) {
      if (cost < pq[location].getCost()) {
        return location;
      } else {
        return location + 1;
      }
    }
    int newSize = size / 2;
    if (cost < pq[location + newSize].getCost()) {
      return binarySearch(cost, newSize, location);
    } else {
      return binarySearch(cost, size - newSize, location + newSize);
    }
  }
 public:
  bool contain(State<T> s) {
    if (this->costOfState.find(s.getState()) == this->costOfState.end()) {
      return false;
    }
    return true;
  }
  void remove(State<T> s) {
    if (!contain(s)) {
      throw "The state does not exist";
    }
    pq.erase(pq.begin() + this->costOfState[s.getState()]);
    this->costOfState.erase(s.getState());
  }
  double getStateCost(State<T> s) {
    if (!contain(s)) {
      throw "The state does not exist";
    }
    return this->pq[this->costOfState[s.getState()]];
  }
  State<T> poll() {
    if (pq.size() == 0) {
      throw "The queue is empty";
    }
    State<T> s = pq[0];
    this->costOfState.erase(s.getState());
    pq.erase(pq.begin());
    return s;
  }
  void push(State<T> s) {
    int i = binarySearch(s.getCost(), pq.size(), 0);
    if (contain(s)) {
      remove(s);
    }
    this->costOfState[s.getState()] = s.getCost();
    pq.insert(pq.begin() + i, s);
  }
  int GetCount() const {
    return pq.size();
  }
  bool isEmpty() {
    return pq.size() == 0;
  }
  void printQueue() {
    for (State<T> s : pq) {
      cout << s.getState() << ": " << s.getCost() << endl;
    }
  }
};
#endif //EX4_5__STATEPRIORITYQUEUE_H_
