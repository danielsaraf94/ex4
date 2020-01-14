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

class ObjectAdapter : public Solver<Problem<MatrixProblem>, Solution<vector<State<Point>>>> {
    Searcher<State<Point>>* searcher;
  MatrixSearchable *searchable;
 public:
  ObjectAdapter(Searcher<State<Point>>*s) {
    searcher = s;
  }
  ObjectAdapter(){};
  Solution<vector<State<Point>>> solve(Problem<MatrixProblem> p) {
    MatrixProblem* m = new MatrixProblem(p.GetProblemDescribe());
    this->searchable = new MatrixSearchable(m);
    return this->searcher->search(*(this->searchable));
  }
};

#endif //EX4__OBJECTADAPTER_H_
