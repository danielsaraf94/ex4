//
// Created by daniels on 11/01/2020.
//

#include <algorithm>
#include "StringReverser.h"
string StringReverser::solve(string str) {
  string reverse_str = str;
  reverse(reverse_str.begin(), reverse_str.end());
  return reverse_str;
}
