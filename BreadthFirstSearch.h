//
// Created by daniels on 12/01/2020.


#ifndef EX4_5__BREADTHFIRSTSEARCH_H_
#define EX4_5__BREADTHFIRSTSEARCH_H_
#include "Searcher.h"
#include "unordered_map"
#include "queue"
template<typename T>
class BreadthFirstSearch : public Searcher<T> {
  Solution<T> search(Searchable<T> searchable) {
    State<T> *v;
    list<State<T> *> list;
    unordered_map<T, bool> map;
    queue<State<T>> queue;
    map[searchable.getInitialState()->getState()] = true;
    queue.push(*(searchable.getInitialState()));
    while (!queue.isEmpty()) {
      v = &(queue.poll());
      if (searchable.isGoalState(v))
        return makeSulotion(v);//here we should return solution
      list = searchable.getAllPossibleStates();
      for (State<T> s : list) {
        if (map.find(s.getState()) == map.end()) {
          map[s.getState()] = true;
          s->setCameFrom(v);
          queue.push(s);
        }
      }
    }
  }
  Solution<T> makeSulotion(State<T> *v) {}
};
#endif //EX4_5__BREADTHFIRSTSEARCH_H_