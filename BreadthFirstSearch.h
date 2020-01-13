//
// Created by daniels on 12/01/2020.
//

#ifndef EX4_5__BREADTHFIRSTSEARCH_H_
#define EX4_5__BREADTHFIRSTSEARCH_H_
#include "ASearcher.h"
template<typename T>
class BreadthFirstSearch : public ASearcher<T> {

  Solution<T> search(Searchable<T> searchable) {
    State<T> *v;
    list<State<T>*> list;
    unordered_map<T, bool> map;
    map[searchable.getInitialState()->getState()] = true;
    ASearcher<T>::PushOpenList(*(searchable.getInitialState()));
    while (!(ASearcher<T>::isEmpty())) {
      v = &(ASearcher<T>::popOpenList());
      if (searchable.isGoalState(v))
        return v;//here we should return solution
      map[v->getState()] = true;
      list = searchable.getAllPossibleStates();
      for (State<T> s : list) {
        if (map.find(s) == map.end()) {
          map[s] = true;
          s->setCameFrom(v);
          ASearcher<T>::PushOpenList(s);
        }
      }
    }
  }
};
#endif //EX4_5__BREADTHFIRSTSEARCH_H_
