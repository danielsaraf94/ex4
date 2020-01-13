//
// Created by shlomo on 12/01/2020.
//

#ifndef EX4__STATE_H_
#define EX4__STATE_H_
template<typename T>
class State {
  T state;
  double cost;
 public:
  T GetState() const;
 private:
  State<T> *cameFrom;
 public:
  template<typename P>
  friend bool operator<(State<P> const &a, State<P> const &b);
  State<T>(T s) {
    this->state = s;
  }
  double getCost() { return cost; }
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
};

template<typename P>
bool operator<(const State<P> &a, const State<P> &b) {
  return a.cost < b.cost;
}


#endif //EX4__STATE_H_
