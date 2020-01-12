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
  return this->boolMap[s];
}
//check if we are not exceeding
void FileCacheManager::checkCache() {
  if (this->capacity < this->currentSize) {
    delFromCache(this->doublyList.back().first);
  }
}
bool FileCacheManager::saveSolution(string key, string obj) {
  ofstream out_file{key + "_Solution", ios::binary};
  if (!out_file) {
    return false;
  }
  out_file.clear();
  out_file.write((char *) &obj, sizeof(obj));
  out_file.close();
  this->boolMap[key]=true;
  return true;
}
void FileCacheManager::insert(string key, string obj) {
  if (this->cacheMap.count(key)) {
    delFromCache(key);
  }
  if (!saveSolution(key, obj)) {
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
  string obj;
  ifstream input_file(key + "_" + "Solution");
  if (!input_file) {
    throw "File open error";
  }
  if (!input_file.read((char *) &obj, sizeof(obj))) {
    throw "Extract data error";
  }
  input_file.close();
  return obj;
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
  insert(key, object);
  return object;
}