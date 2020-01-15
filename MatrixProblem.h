//
// Created by daniels on 13/01/2020.
//

#ifndef EX4_5__MATRIXPROBLEM_H_
#define EX4_5__MATRIXPROBLEM_H_
#include "Point.h"
#include <cstring>

using namespace std;
class MatrixProblem {
  int **matrix;
  int rows_num;
  int cols_num;
  Point start;
 public:
  int **GetMatrix() const {
    return matrix;
  }
  int GetRowsNum() const {
    return rows_num;
  }
  int GetColsNum() const {
    return cols_num;
  }
  const Point &GetStart() const {
    return start;
  }
  const Point &GetFinish() const {
    return finish;
  }
 private:
  Point finish;
 public:
  MatrixProblem(){}
  MatrixProblem(int **m, Point s, Point f, int r, int c) {
    this->matrix = m;
    this->start = s;
    this->finish = f;
    this->rows_num = r;
    this->cols_num = c;
  }
  int getValuebyIndex(int x,int y){
    return this->matrix[x][y];
  }
  string toString() {
    char buffer[2048]={0};
    strcat(buffer, to_string(start.getX()).c_str());
    strcat(buffer, to_string(start.getY()).c_str());
    strcat(buffer, to_string(finish.getX()).c_str());
    strcat(buffer, to_string(finish.getY()).c_str());
    for (int i = 0; i < rows_num; i++)
      for (int j = 0; j < cols_num; j++)
        strcat(buffer, to_string(matrix[i][j]).c_str());
    string s = buffer;
    return s;
  }
};
#endif //EX4_5__MATRIXPROBLEM_H_
