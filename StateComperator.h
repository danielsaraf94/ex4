//
// Created by daniels on 12/01/2020.
//

#ifndef EX4_5__STATECOMPERATOR_H_
#define EX4_5__STATECOMPERATOR_H_
#include "State.h"
#include <bits/stdc++.h>
using namespace std;
template<typename T>
class StateComperator {
 public:
  int operator() (const State<T>& s1, const State<T>& s2)
  {
    return s1.getCost() > s2.getCost();
  }
};
#endif //EX4_5__STATECOMPERATOR_H_
