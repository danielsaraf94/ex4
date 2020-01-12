//
// Created by daniels on 12/01/2020.
//

#ifndef EX4_5__BREADTHFIRSTSEARCH_H_
#define EX4_5__BREADTHFIRSTSEARCH_H_
#include "ASearcher.h"
template<typename T>
class BreadthFirstSearch: public ASearcher<T>{
  Solution<T> search(Searchable<T> searchable){
        State<T> v;
        list<State<T>> list;
    ASearcher<T>:: PushOpenList(searchable.getInitialState());
        while(ASearcher<T>::isEmpty()){
              v = ASearcher<T>::popOpenList();
            if (searchable.isGoalState(v))
                return v;
            list=searchable.getAllPossibleStates();
            for (State<T> s : list){
               if w is not labeled as discovered then
                   label w as discovered
                   w.parent := v
                   Q.enqueue(w)}
}}
};
#endif //EX4_5__BREADTHFIRSTSEARCH_H_
