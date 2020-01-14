//
// Created by daniels on 13/01/2020.
//

#ifndef EX4_5__POINT_H_
#define EX4_5__POINT_H_
#include <iostream>
using namespace std;
class Point{
  int x,y;
 public:
  int getX() const;
  void setX(int x);
  int getY() const;
  void setY(int y);
  friend ostream& operator<<(std::ostream& os, Point const& p);
};

#endif //EX4_5__POINT_H_
