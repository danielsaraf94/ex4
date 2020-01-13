//
// Created by daniels on 13/01/2020.
//

#ifndef EX4_5__POINT_H_
#define EX4_5__POINT_H_
class Point{
  int x,y;
 public:
  int getX() const {
    return x;
  }
  void setX(int x) {
    Point::x = x;
  }
  int getY() const {
    return y;
  }
  void setY(int y) {
    Point::y = y;
  }
};
#endif //EX4_5__POINT_H_
