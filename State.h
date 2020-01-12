//
// Created by shlomo on 12/01/2020.
//

#ifndef EX4__STATE_H_
#define EX4__STATE_H_
template<typename T>
class State {
  T state;
  double cost;
  State<T> *cameFrom;
 public:
  State<T>(T s) {
    this->state = s;
  }
  double getCost() { return cost; }
  void setCost(double d) { cost = d; }
  bool equals(State<T> s) {
    return state == s.state;
  }
};

#endif //EX4__STATE_H_
