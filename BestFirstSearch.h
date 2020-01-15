//
// Created by shlomo on 12/01/2020.
//

#ifndef EX4_BFS_H
#define EX4_BFS_H
#include "Searcher.h"
#include "Solution.h"
#include "State.h"
#include "set"
#include "vector"
#include "list"
#include "StatePriorityQueue.h"
using namespace std;
template<typename T>
class BestFirstSearch : public Searcher<T, vector<State<T>>> {
  int i = 0;
  int evaluatedNodes;
  StatePriorityQueue<T> open_list;
  set<State<T>> closed;
  Searcher<T, vector<State<T>>>* getClone(){
    return new BestFirstSearch<T>();
  };
  Solution<vector<State<T>>> backTrace(State<T> s) {
    vector<State<T>> vec;
    vec.push_back(s);
    while (s.getCameFrom() != NULL) {
      s = *(s.getCameFrom());
      vec.push_back(s);
    }
    vector<State<T>> ret_vec;
    for (int i = vec.size() - 1; i >= 0; i--) {
      ret_vec.push_back(vec[i]);
    }
    Solution<vector<State<T>>> solution;
    solution.SetSolutionDescribe(ret_vec);
    return solution;
  }

  State<T> popOpenList() {
    evaluatedNodes++;
    return open_list.poll();
  }
 public:

  BestFirstSearch<T>() : Searcher<T, vector<State<T>>>() {
    this->evaluatedNodes = 0;
    open_list = StatePriorityQueue<T>();
  }

  int getNumberOfNodeEvaluated() {
    return evaluatedNodes;
  }

  Solution<vector<State<T>>> search(Searchable<T> &s) {
    evaluatedNodes = 0;
    while (!(open_list.isEmpty()))
      open_list.poll();
    closed.clear();
    unordered_map<T, bool> map;
    open_list.push(*(s.getInitialState()));
    while (!open_list.isEmpty()) {
      evaluatedNodes++;
      State<T> *n = new State<T>(open_list.poll());
      closed.insert(*n);
      map[n->getState()] = true;
      if (s.isGoalState(n)) {
        return backTrace(*n);
      }
      list<State<T> *> successors = s.getAllPossibleStates(n);
      for (State<T> *state: successors) {
        if (map.find(state->getState()) == map.end() && !open_list.contain(*state)) {
          open_list.push(*state);
        } else if (open_list.contain(*state)) {
          if (state->getCost() < open_list.getStateCost(*state)) {
            open_list.remove(*state);
            open_list.push(*state);
          }
        }else{
          open_list.push(*state);
        }
      }
    }
  }
};

#endif //EX4_BFS_H