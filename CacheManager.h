//
// Created by shlomo on 11/01/2020.
//

#ifndef EX4__CACHEMANAGER_H_
#define EX4__CACHEMANAGER_H_
#include <iostream>
using namespace std;
class CacheManager {
 public:
  virtual bool saveSolution(string, string) = 0;
  virtual bool isThereSolution(string) = 0;
  virtual string getSolution(string) = 0;
  virtual ~CacheManager() {};
};

#endif //EX4__CACHEMANAGER_H_