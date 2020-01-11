//
// Created by shlomo on 11/01/2020.
//

#ifndef EX4__FILECACHEMANAGER_H_
#define EX4__FILECACHEMANAGER_H_
#include "CacheManager.h"
#include "unordered_map"
using namespace std;
class FileCacheManager : public CacheManager {
  unordered_map<string,bool> map;
  virtual void saveSolution(string,string);
  void getMapInfo();
 public:
  FileCacheManager();
  virtual bool isThereSolution(string);
  virtual string getSolution(string);
  virtual ~FileCacheManager();
};

#endif //EX4__FILECACHEMANAGER_H_
