//
// Created by shlomo on 11/01/2020.
//
#include <iostream>
#include <fstream>
#include "FileCacheManager.h"
void FileCacheManager::saveSolution(int key, Solution *s) {
  ofstream out_file{"Solution_"+to_string(key), ios::binary};
  if (!out_file) {
    throw "Cannot open file";
  }
  out_file.clear();
  out_file.write((char *) &s, sizeof(*s));
  out_file.close();
}
bool FileCacheManager::isThereSolution(Problem * p) {
  return (this->map[p]);
}
Solution *FileCacheManager::getSolution(Problem *p) {
  Solution s;
  ifstream input_file("Solution_"+to_string(p->getKey()));
  if (!input_file) {
    throw "File open error";
  }
  if (!input_file.read((char *) &s, sizeof(s))) {
    throw "Extract Solution error";
  }
  input_file.close();
  return &s;
}
