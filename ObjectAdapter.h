//
// Created by shlomo on 13/01/2020.
//

#ifndef EX4__OBJECTADAPTER_H_
#define EX4__OBJECTADAPTER_H_
template<typename T>
class ObjectAdapter : public Solver<Problem < MatrixProblem>, Solution<T>>{
Searcher *searcher;
public:
ObjectAdapter(Searcher *s) {
  searcher = s;
}
Solution<T> solve(){

}
};

#endif //EX4__OBJECTADAPTER_H_
