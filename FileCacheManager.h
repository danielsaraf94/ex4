//
// Created by shlomo on 11/01/2020.
//

#ifndef EX4__FILECACHEMANAGER_H_
#define EX4__FILECACHEMANAGER_H_
#include "CacheManager.h"
#include "unordered_map"
#include "list"
using namespace std;
class FileCacheManager : public CacheManager {
  int currentSize;
  int capacity;
  list<pair<string, string>> doublyList;
  unordered_map<string, typename list<pair<string, string>>::iterator> cacheMap;
  unordered_map<string,bool> boolMap;
  void delFromCache(string);
  void checkCache();
  void insert(string,string);
  string readFromFile(string);
  bool saveSolution(string,string);
 public:
  FileCacheManager();
  bool isThereSolution(string);
  string getSolution(string);
};

#endif //EX4__FILECACHEMANAGER_H_
