//
// Created by shlomo on 14/01/2020.
//

#include "MatrixSearchable.h"
MatrixSearchable::MatrixSearchable(MatrixProblem* m) {
  this->matrix_problem=m;
}
bool MatrixSearchable::isGoalState(State<Point> *s) {
  return (this->matrix_problem->GetFinish()==s->getState());
}
State<Point>* MatrixSearchable::getInitialState() {
  Point p = this->matrix_problem->GetStart();
  State<Point>* newState = new State<Point>(p);
  int value = this->matrix_problem->getValuebyIndex(p.getX(),p.getX());
  newState->setCameFrom(NULL);
  newState->setCost(value);
  return newState;
}
list<State<Point> *> MatrixSearchable::getAllPossibleStates(State<Point> *s) {
  list<State<Point>*> list;
  int x = s->getState().getX();
  int y = s->getState().getY();
  if(x>0){
    Point p{x-1,y};
    int value = this->matrix_problem->getValuebyIndex(x-1,y);
    if(value!=-1){
      State<Point>* newState = new State<Point>(p);
      newState->setCameFrom(s);
      newState->setCost(s->getCost()+value);
      list.push_front(newState);
    }
  }
  if(y>0){
    Point p{x,y-1};
    int value = this->matrix_problem->getValuebyIndex(x,y-1);
    if(value!=-1){
      State<Point>* newState = new State<Point>(p);
      newState->setCameFrom(s);
      newState->setCost(s->getCost()+value);
      list.push_front(newState);
    }
  }
  if(x<(matrix_problem->GetRowsNum()-1)){
    Point p{x+1,y};
    int value = this->matrix_problem->getValuebyIndex(x+1,y);
    if(value!=-1){
      State<Point>* newState = new State<Point>(p);
      newState->setCameFrom(s);
      newState->setCost(s->getCost()+value);
      list.push_front(newState);
    }
  }
  if(y<(matrix_problem->GetColsNum()-1)){
    Point p{x,y+1};
    int value = this->matrix_problem->getValuebyIndex(x,y+1);
    if(value!=-1){
      State<Point>* newState = new State<Point>(p);
      newState->setCameFrom(s);
      newState->setCost(s->getCost()+value);
      list.push_front(newState);
    }
  }
  return list;
}