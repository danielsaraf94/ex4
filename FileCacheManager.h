//
// Created by shlomo on 11/01/2020.
//

#ifndef EX4__FILECACHEMANAGER_H_
#define EX4__FILECACHEMANAGER_H_
#include "CacheManager.h"
class FileCacheManager : public CacheManager {
  virtual void saveSolution(Problem *, Solution *);
 public:
  virtual bool isThereSolution(Problem *);
  virtual Solution *getSolution(Problem *);
};

#endif //EX4__FILECACHEMANAGER_H_
