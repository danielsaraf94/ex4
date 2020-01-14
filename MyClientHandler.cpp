// Created by daniels on 11/01/2020.

#include "MyClientHandler.h"
#include <cstring>
#include <algorithm>
#include <vector>
#include <iostream>
#include <cstdlib>
#include "MatrixProblem.h"
#include "Solution.h"
#include "State.h"
using namespace std;
MyClientHandler::MyClientHandler(CacheManager<string, string> *c, Solver<Problem<MatrixProblem>, Solution<string>> *s) {
  this->cache_manager = c;
  this->solver = s;
}
int MyClientHandler::getNumberOfCols(string line) {
  int c = 1;
  for (char ch:line) {
    if (ch == ',')
      c++;
  }
  return c;
}
void MyClientHandler::handleClient(int client_socket) {
  char all_matrix[5000] = {0};
  char buffer[1024] = {0};
  vector<string> from_client;
  string str;
  string solve_str;
  // read from client
  read(client_socket, buffer, 1024);
  str = buffer;
  strcat(all_matrix, buffer);
  string end = "end";
  while (end != str) {
    cout << str << endl;
    char buffer[1024] = {0};
    read(client_socket, buffer, 1024);
    strcat(all_matrix, buffer);
    str = buffer;
  }
  int i = 0;
  while (all_matrix[i] != 'e') {
    string temp = "";
    while (all_matrix[i] != '\n') {
      temp += all_matrix[i];
      i++;
    }
    i++;
    from_client.insert(from_client.end(), temp);
  }

  string number, line;
  int r = (int) from_client.size() - 2;
  int c = getNumberOfCols(from_client[0]);
  int **matrix = (int **) malloc(r * sizeof(int *));
  for (int i = 0; i < r; i++)
    matrix[i] = (int *) malloc(c * sizeof(int));

  for (int i = 0; i < r; i++) {
    int j = 0;
    line = from_client[i];
    size_t pos = 0;
    while ((pos = line.find(",")) != std::string::npos) {
      number = line.substr(0, pos);
      line.erase(0, pos + 1);
      matrix[i][j] = stoi(number);
      j++;
    }
    pos = line.length();
    number = line.substr(0, pos);
    line.erase(0, pos + 1);
    matrix[i][j] = stoi(number);
  }
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      cout << matrix[i][j]<<" ";
    }
    cout << endl;
  }

  Point start, finish;
  line = from_client[from_client.size() - 2];
  size_t pos = 0;
  pos = line.find(",");
  number = line.substr(0, pos);
  line.erase(0, pos + 1);
  start.setX(stoi(number));
  pos = line.length();
  number = line.substr(0, pos);
  line.erase(0, pos + 1);
  start.setY(stoi(number));
  line = from_client[from_client.size() - 1];
  pos = line.find(",");
  number = line.substr(0, pos);
  line.erase(0, pos + 1);
  finish.setX(stoi(number));
  pos = line.length();
  number = line.substr(0, pos);
  line.erase(0, pos + 1);
  finish.setY(stoi(number));
  MatrixProblem matrix_problem(matrix, start, finish, r, c);
  hash < string > hasher;
  auto hashed = hasher(matrix_problem.toString());
  string key = to_string(hashed);
  if (cache_manager->isThereSolution(key)) {
    solve_str = cache_manager->getSolution(key);
    cout << key << ": got it!" << endl;
  } else {
    cout << key << ": didnt got it!" << endl;
    auto *problem = new Problem<MatrixProblem>(matrix_problem);
    solve_str = (solver->solve(*problem)).GetSolutionDescribe();
    cache_manager->saveSolution(key, solve_str);
  }
  char *temp = new char[solve_str.length() + 1];
  strcpy(temp, solve_str.c_str());
  int is_sent = send(client_socket, temp, strlen(temp), 0);
  delete (temp);
  if (is_sent == -1) {
    std::cout << "Error sending message" << std::endl;
  }

  close(client_socket);
}

