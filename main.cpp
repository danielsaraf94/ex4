//
#include "MyClientHandler.h"
#include "MyTestClientHandler.h"
#include "FileCacheManager.h"
#include "StringReverser.h"
#include "State.h"
#include "StatePriorityQueue.h"
#include "Point.h"
#include "ObjectAdapter.h"
#include "MyParallelServer.h"
#include "BreadthFirstSearch.h"
#include "BestFirstSearch.h"
using namespace std;
int main(int argc, char *argv[]) {
 /* StatePriorityQueue<Point> s;
  State<Point> s1(Point(2,3));
  s1.setCost(2);
  State<Point> s2(Point(2,3));
  s2.setCost(4);
  s.push(s1);
  cout<<s.contain(s2)<<endl;
  */

  MyParallelServer server;
  ObjectAdapter sr(new BestFirstSearch<Point>());
  FileCacheManager fcm;
  MyClientHandler ch(&fcm, &sr);
  server.open(atoi(argv[1]), &ch);
  return 0;
}