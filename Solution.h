//
// Created by daniels on 12/01/2020.

#ifndef EX4_5__SOLUTION_H_
#define EX4_5__SOLUTION_H_
template<typename T>
class Solution{
 private:
  T solution_describe;
 public:
  T GetSolutionDescribe() const {
    return solution_describe;
  }
  void SetSolutionDescribe(T solution_describe) {
    Solution::solution_describe = solution_describe;
  }
};
#endif //EX4_5__SOLUTION_H_
