//
// Created by shlomo on 11/01/2020.
//

#ifndef EX4__FILECACHEMANAGER_H_
#define EX4__FILECACHEMANAGER_H_
#include "CacheManager.h"
#include "unordered_map"
using namespace std;
class FileCacheManager : public CacheManager {
  int numberOfSolutions;
  unordered_map<Problem*,int> map;
  virtual void saveSolution(int, Solution *);
 public:
  FileCacheManager(){numberOfSolutions=0;};
  virtual bool isThereSolution(Problem *);
  virtual Solution *getSolution(Problem *);
};

#endif //EX4__FILECACHEMANAGER_H_
