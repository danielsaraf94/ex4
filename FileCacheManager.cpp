//
// Created by shlomo on 11/01/2020.
//
#include <iostream>
#include <fstream>
#include "FileCacheManager.h"

FileCacheManager::FileCacheManager() {
  this->currentSize = 0;
  this->capacity = 5;
}

void FileCacheManager::delFromCache(string key) {
  typename list<pair<string, string>>::iterator it1 = this->cacheMap[key], it2 = this->cacheMap[key];
  advance(it2, 1);
  this->doublyList.erase(it1, it2);
  this->cacheMap.erase(key);
  this->currentSize--;
}
bool FileCacheManager::isThereSolution(string s) {
  bool isSolve = boolMap[s];
  return isSolve;
}
//check if we are not exceeding
void FileCacheManager::checkCache() {
  if (this->capacity < this->currentSize) {
    delFromCache(this->doublyList.back().first);
  }
}
bool FileCacheManager::printToFile(string key, string obj) {
  ofstream outfile("Solution_" + key + ".txt");
  if (!outfile) {
    return false;
  }
  outfile.clear();
  outfile << obj << endl;
  outfile.close();

  this->boolMap[key] = true;
  return true;
}
void FileCacheManager::saveSolution(string key, string obj) {
  if (this->cacheMap.count(key)) {
    delFromCache(key);
  }
  if (!printToFile(key, obj)) {
    throw "File open error";
  }
  pair<string, string> pair{key, obj};
  this->doublyList.push_front(pair);
  this->cacheMap[key] = (this->doublyList.begin());
  this->currentSize++;
  this->boolMap[key] = true;
  //check if we are not exceeding
  checkCache();
}
string FileCacheManager::readFromFile(string key) {
  string line;
  string all_file = "";
  ifstream input_file("Solution_" + key + ".txt");
  if (input_file.is_open()) {
    while (getline(input_file, line)) {
      all_file += line;
    }
    input_file.close();
  } else cout << "Unable to open file";
  return all_file;
}

string FileCacheManager::getSolution(string key) {
  string object;
  if (this->cacheMap.count(key)) {
    object = this->cacheMap[key]->second;
  } else {
    //read from file
    try {
      object = readFromFile(key);
    } catch (const char *e) {
      throw e;
    }
  }
  saveSolution(key, object);
  return object;
}