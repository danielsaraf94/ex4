//
// Created by shlomo on 13/01/2020.
//

#ifndef EX4__OBJECTADAPTER_H_
#define EX4__OBJECTADAPTER_H_
#include "Searcher.h"
#include "Solver.h"
#include "MatrixProblem.h"
#include "Searcher.h"
#include "Searchable.h"
#include "MatrixSearchable.h"

class ObjectAdapter : public Solver<Problem<MatrixProblem>, Solution<string>> {
  Searcher<Point, vector<State<Point>>> *searcher;
  MatrixSearchable *searchable;
 public:
  ObjectAdapter(Searcher<Point, vector<State<Point>>> *s) {
    searcher = s;
  }
  ObjectAdapter() {};
  Solution<string> solve(Problem<MatrixProblem> p) {
    MatrixProblem *m = new MatrixProblem(p.GetProblemDescribe());
    this->searchable = new MatrixSearchable(m);
    return adapt(this->searcher->search(*(this->searchable)));
  }
  Solution<string> adapt(Solution<vector<State<Point>>> s) {
    string str = "";
    vector<State<Point>> vec = s.GetSolutionDescribe();
    for (int i = 0; i < vec.size() - 1; i++) {
      int x = vec[i].getState().getX();
      int y = vec[i].getState().getY();
      int x2 = vec[i + 1].getState().getX();
      int y2 = vec[i + 1].getState().getY();
      double cost = vec[i+1].getCost();
      if (x > x2) {
        str+="Down ";
      }
      if (x < x2) {
        str += "Up ";
      }
      if(y<y2){
        str+="Left ";
      }
      if(y>y2){
        str+="Right ";
      }
      str+="("+to_string(cost)+")";
      if(i!=vec.size()-2){
        str+=", ";
      }
    }
  }
};

#endif //EX4__OBJECTADAPTER_H_
