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
template<typename T, typename P>
class DepthFirstSearch : public Searcher<T, P> {
  int num_of_node_evaluated = 0;
 public:
  int getNumberOfNodeEvaluated() { return num_of_node_evaluated; }
  Solution<P> search(Searchable<T> searchable) {
    stack<State<T>> stack;
    State<T> *v;
    list<State<T> *> list;
    unordered_map<T, bool> discovered_map;
    stack.push(searchable.getInitialState());
    while (!stack.empty()) {
      num_of_node_evaluated++;
      v = stack.pop();
      if (discovered_map.find(v->getState()) == discovered_map.end()) {
        discovered_map[v->getState()] = true;
        list = searchable.getAllPossibleStates(v);
        for (State<T> s : list) {
          stack.push(s);
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
