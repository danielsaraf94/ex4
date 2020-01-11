//
// Created by shlomo on 11/01/2020.
//
#include <iostream>
#include <fstream>
#include "FileCacheManager.h"
FileCacheManager::FileCacheManager() {
  try{
    getMapInfo();
  }catch(...){

  }
}

void FileCacheManager:: getMapInfo(){
  ifstream input_file("Map_Information");
  if (!input_file) {
    throw "File open error";
  }
  if (!input_file.read((char *) &this->map, sizeof(this->map))) {
    throw "Extract Solution error";
  }
  input_file.close();
}

FileCacheManager::~FileCacheManager() {
  ofstream out_file{"Map_Information", ios::binary};
  if (!out_file) {
    throw "Cannot open file";
  }
  out_file.clear();
  out_file.write((char *) &this->map, sizeof(this->map));
  out_file.close();
}

void FileCacheManager::saveSolution(string problem, string solution) {
  ofstream out_file{"Solution_" + problem, ios::binary};
  if (!out_file) {
    throw "Cannot open file";
  }
  out_file.clear();
  out_file.write((char *) &solution, sizeof(solution));
  this->map[problem] = true;
  out_file.close();
}

bool FileCacheManager::isThereSolution(string problem) {
  return this->map[problem];
}

string FileCacheManager::getSolution(string problem) {
  string s;
  ifstream input_file("Solution_" + problem);
  if (!input_file) {
    throw "File open error";
  }
  if (!input_file.read((char *) &s, sizeof(s))) {
    throw "Extract Solution error";
  }
  input_file.close();
  return s;
}
