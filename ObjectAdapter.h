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

class ObjectAdapter : public Solver<Problem<MatrixProblem>, Solution<string>>{
Searcher<string> *searcher;
Searchable<string> *searchable;
public:
  ObjectAdapter(){}
ObjectAdapter(Searcher<string> *s) {
  searcher = s;
}
Solution<string> solve(Problem<MatrixProblem> p){

}
};

#endif //EX4__OBJECTADAPTER_H_
