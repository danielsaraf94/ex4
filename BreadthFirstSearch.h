//
// Created by daniels on 12/01/2020.


#ifndef EX4_5__BREADTHFIRSTSEARCH_H_
#define EX4_5__BREADTHFIRSTSEARCH_H_
#include "Searcher.h"
#include "unordered_map"
#include "queue"
template<typename T>
class BreadthFirstSearch : public Searcher<T, vector<State<T>>> {
  int num_of_node_evaluated = 0;
 public:
  Searcher<T, vector<State<T>>> *getClone() {
    return new BreadthFirstSearch<T>();
  };
  int getNumberOfNodeEvaluated() { return num_of_node_evaluated; }
  Solution<vector<State<T>>> search(Searchable<T> &searchable) {
    State<T> *v;
    list<State<T> *> list;
    unordered_map<T, bool> map;
    queue<State<T> *> queue;
    queue.push((searchable.getInitialState()));
    map[queue.front()->getState()] = true;
    while (!(queue.empty())) {
      num_of_node_evaluated++;
      v = queue.front();
      queue.pop();
      if (searchable.isGoalState(v)) {
        State<T> goal = (*v);

        while (!(queue.empty())) {
          queue.pop();
        }
        return backTrace(goal);
      }
      list = searchable.getAllPossibleStates(v);
      for (State<T> *s : list) {
        if (map.find(s->getState()) == map.end()) {
          map[s->getState()] = true;
          s->setCameFrom(v);
          queue.push(s);
        }
      }
    }
    throw "cant reach goal";
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
  int getSearcherID(){return 3;}
};

#endif //EX4_5__BREADTHFIRSTSEARCH_H_