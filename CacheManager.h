//
// Created by shlomo on 11/01/2020.
//

#ifndef EX4__CACHEMANAGER_H_
#define EX4__CACHEMANAGER_H_
#include "Problem.h"
#include "Solution.h"
class CacheManager {
  virtual void saveSolution(Problem*,Solution*)=0;
 public:
  virtual bool isThereSolution(Problem*)=0;
  virtual Solution getSolution(Problem*)=0;
  virtual ~CacheManager(){};
};

#endif //EX4__CACHEMANAGER_H_
