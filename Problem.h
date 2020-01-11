//
// Created by shlomo on 11/01/2020.


#ifndef EX4__PROBLEM_H_
#define EX4__PROBLEM_H_

class Problem {
 protected:
 int key;
 public:
  Problem(int k){
    this->key = k;
  }
  virtual int getKey()=0;
};

#endif //EX4__PROBLEM_H_
