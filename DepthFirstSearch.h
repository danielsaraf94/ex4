//
// Created by daniels on 14/01/2020.
//

#ifndef EX4_5__DEPTHFIRSTSEARCH_H_
#define EX4_5__DEPTHFIRSTSEARCH_H_
//
// Created by daniels on 12/01/2020.

#include <stack>
#include "Searcher.h"
#include "unordered_map"
#include "queue"
#include "StateStack.h"
template<typename T>
class DepthFirstSearch : public Searcher<T, vector<State<T>>> {
  int num_of_node_evaluated = 0;
 public:
  Searcher<T, vector<State<T>>> *getClone() {
    return new DepthFirstSearch<T>();
  };
  int getNumberOfNodeEvaluated() { return num_of_node_evaluated; }
  Solution<vector<State<T>>> search(Searchable<T> &searchable) {
    Stack<State<T>> stack;
    State<T> *v;
    State<T> *prev_v = NULL;
    list<State<T> *> list;
    unordered_map<T, bool> discovered_map;
    stack.push(*(searchable.getInitialState()));
    while (!stack.empty()) {
      num_of_node_evaluated++;
      v = new State<T>(stack.top().getState());
      v->setCost(stack.top().getCost());
      stack.pop();
      v->setCameFrom(prev_v);
      prev_v = v;
      if (searchable.isGoalState(v))
        return backTrace(*v);
      if (discovered_map.find(v->getState()) == discovered_map.end()) {
        discovered_map[v->getState()] = true;
        list = searchable.getAllPossibleStates(v);
        for (State<T> *s : list) {
          if (discovered_map.find(s->getState()) == discovered_map.end())
            stack.push(*s);
        }
      }
    }
  }
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
};

#endif //EX4_5__DEPTHFIRSTSEARCH_H_
