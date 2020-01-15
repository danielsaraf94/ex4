//
// Created by shlomo on 12/01/2020.
//

#ifndef EX4__STATE_H_
#define EX4__STATE_H_
#include "Point.h"
template<typename T>
class State {
  T state;
  double cost;
  State<T> *cameFrom = nullptr;
 public:
  bool operator<(const State &a) const {
    return cost < a.cost;
  }
  bool operator==(const State &a) const {
    return (getState() == a.getState());
  }
  bool operator!=(const State &a) const {
    return !(*this == *a);
  }
  State<T>(int cost,T state, State<T>* cameFrom) {
    this->cost = cost;
    this->state = state;
    this->cameFrom = cameFrom;
  }
  State<T>(T s) {
    this->state = s;
  }
  State<T>() {

  }
  double getCost() const { return cost; }
  void setCost(double d) { cost = d; }
  bool equals(State<T> s) {
    return state == s.state;
  }
  T getState() const {
    return state;
  }
  void setCameFrom(State<T> *came_from) {
    cameFrom = came_from;
  }
  State<T> *getCameFrom() {
    return cameFrom;
  }
};

namespace std {
template<>
struct hash<State<Point>> {
  std::size_t operator()(const State<Point> &s) const {
    using std::size_t;
    using std::hash;
    using std::string;

    std::size_t h1 = std::hash<Point>{}(s.getState());
    return h1;
  }
};
}

#endif //EX4__STATE_H_
