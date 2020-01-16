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
  Solver* getClone() {return new ObjectAdapter(searcher->getClone());}
  ObjectAdapter() {};
  Solution<string> solve(Problem<MatrixProblem> p) {
    MatrixProblem *m = new MatrixProblem(p.GetProblemDescribe());
    this->searchable = new MatrixSearchable(m);
    Solution<string> newSol= adapt(this->searcher->search(*(this->searchable)));
    delete(m);
    delete(searchable);
    return newSol;
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
        str+="Up ";
      }
      if (x < x2) {
        str += "Down ";
      }
      if(y<y2){
        str+="Right ";
      }
      if(y>y2){
        str+="Left ";
      }
      str+="("+to_string((int)cost)+")";
      if(i!=vec.size()-2){
        str+=", ";
      }
    }
    Solution<string> solution;
    solution.SetSolutionDescribe(str);
    int sum = searcher->getNumberOfNodeEvaluated();
    cout<<sum<<endl;
    return solution;
  }
};

#endif //EX4__OBJECTADAPTER_H_
