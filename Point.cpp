//
// Created by shlomo on 14/01/2020.
//

#include "Point.h"
ostream& operator<<(ostream& os, Point const& p)
{
  os<<"Point("<<p.getX()<<","<<p.getY()<<")";
  return os;
}
int Point:: getX() const {
  return x;
}
void Point:: setX(int x) {
  Point::x = x;
}
int Point:: getY() const {
  return y;
}
void Point:: setY(int y) {
  Point::y = y;
}