// Created by daniels on 11/01/2020.


#include <cstring>
#include <algorithm>
#include <vector>
#include "MyClientHandler.h"
#include <iostream>
#include <cstdlib>
using namespace std;
MyClientHandler::MyClientHandler(CacheManager<string, string> *c, Solver<string, string> *s) {
  this->cache_manager = c;
  this->solver = s;
}
void MyClientHandler::handleClient(int client_socket) {
  char buffer[1024] = {0};
  string str;
  string reverse_str;
  // read from client
  read(client_socket, buffer, 1024);
  str = buffer;
  string end = "end";
  vector<string> from_client;
  while (end != str) {
    cout << str << endl;
    from_client.insert(from_client.end(), str);
    char buffer[1024] = {0};
    read(client_socket, buffer, 1024);
    str = buffer;
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
      cout << matrix[i][j] << "  ";
    }
    cout << endl;
  }

/* if (cache_manager->isThereSolution(str)) {
   reverse_str = cache_manager->getSolution(str);
   cout<< str <<": got it!"<<endl;
 } else {
   cout<< str <<": didnt got it!"<<endl;
   reverse_str = solver->solve(str);
   cache_manager->saveSolution(str, reverse_str);
 }
 char *c = new char[reverse_str.length() + 1];
 strcpy(c, reverse_str.c_str());
 int is_sent = send(client_socket, c, strlen(c), 0);
 char buffer[1024] = {0};
 read(client_socket, buffer, 1024);
 str = buffer;
 delete (c);
 if (is_sent == -1) {
   std::cout << "Error sending message" << std::endl;
 }*/
  close(client_socket);
}

int MyClientHandler::getNumberOfCols(string line) {
  int c = 1;
  for (char ch:line) {
    if (ch == ',')
      c++;
  }
  return c;
}