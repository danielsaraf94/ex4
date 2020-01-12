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
class ASearcher : public Searcher<T>{
 private:
  StatePriorityQueue open_list;
  int evaluatedNodes;
 protected:
  State<T> popOpenList(){
    evaluatedNodes++;
    return open_list.poll();
  }
 public:
  ASearcher(){
    open_list = new StatePriorityQueue();
    evaluatedNodes=0;
  }

};
#endif //EX4_5__ASEARCHER_H_
