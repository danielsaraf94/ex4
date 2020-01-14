//
// Created by shlomo on 12/01/2020.
//

#ifndef EX4__BFS_H_
#define EX4__BFS_H_
#include "Searcher.h"
#include "Solution.h"
#include "State.h"
#include "set"
#include "vector"
#include "list"
#include "StatePriorityQueue.h"
using namespace std;
template<typename T>
class BestFirstSearch : public Searcher<T> {
  int evaluatedNodes;
  set<State<T>> closed;
  Solution<vector<State<T>>> backTrace(State<T> s){
    vector<State<T>> vec;
    vec.push_back(s);
    while(s.getCameFrom()!=NULL){
      s=*(s.getCameFrom());
      vec.push_back(s);
    }
    vector<State<T>> ret_vec;
    for(int i = vec.size()-1; i>=0;i--){
      ret_vec.push_back(vec[i]);
    }
    Solution<vector<State<T>>> solution;
    solution.SetSolutionDescribe(ret_vec);
    return solution;
  }
  StatePriorityQueue<T> open_list;

  State<T> popOpenList() {
    evaluatedNodes++;
    return open_list.poll();
  }
 public:
  BestFirstSearch<T>() : Searcher<T>() {
    this->evaluatedNodes = 0;
    open_list = new StatePriorityQueue<T>();
  }

  int getNumberOfNodesEvaluated() {
    return evaluatedNodes;
  }

  Solution<vector<State<T>>> search(Searchable<T> s) {
    this->open_list.push(*(s.getInitialState()));
    while (!this->open_list.isEmpty()) {
      State<T> n = popOpenList();
      this->closed.insert(n);
      if (s.isGoalState(n)) {
        return backTrace(*s);
      }
      list<State<T>*> successors = s.getAllPossibleStates(n);
      for (State<T>* state: successors) {
        if (!closed.count(*state) && !this->open_list.contain(*state)) {
          this->open_list.push(*state);
        } else if (this->open_list.contain(*state)) {
          if (state->getCost()<this->open_list.getStateCost(*state)){
            this->open_list.remove(*state);
            this->open_list.push(state);
          }
        }
      }
    }
  }
};

#endif //EX4__BFS_H_
