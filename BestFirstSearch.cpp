//
// Created by shlomo on 12/01/2020.
//
#include "BestFirstSearch.h"
#include "list"
Solution<T> BestFirstSearch:: search(Searchable<T> s){
  ASearcher::PushOpenList(s.getInitialState());
  while(!ASearcher::isemty()){
    State<T> n=ASearcher::popOpenList();
    this->closed.insert(n);
    if(s.isGoalState(n)){
      return backTrace();
    }
    list<State<T>> successors = s.getAllPossibleStates(n);
    for(State s: successors){
      if(!closed.count(s)&&ASearcher::openContaines(s)){
        ASearcher::PushOpenList(s);
      }else if(ASearcher::openContaines(S)){
        if(ASearcher::)
      }
    }
  }
}