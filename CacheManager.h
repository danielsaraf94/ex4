//
// Created by shlomo on 11/01/2020.
//

#ifndef EX4__CACHEMANAGER_H_
#define EX4__CACHEMANAGER_H_
#include "Problem.h"
#include "Solution.h"
class CacheManager {
 public:
  CacheManager(){};
  virtual bool isThereSolution(&Problem)=0;
  virtual &Solution getSolution(&Problem)=0;
  //maybe its should be a private method
  virtual void saveSolution(&Problem,&Solution)=0;
};

#endif //EX4__CACHEMANAGER_H_
