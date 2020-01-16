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
#include "DepthFirstSearch.h"
#include "AStar.h"
using namespace std;
int main() {
  // allocate all the necessary object to get and solve a problem and run the parallel server -
  MyParallelServer server;
  Searcher<Point, vector<State<Point>>> *s = new AStar<Point>();
  ObjectAdapter sr(s);
  FileCacheManager fcm;
  MyClientHandler ch(&fcm, &sr);
  server.open(5600, &ch);
  delete (s);
  return 0;
}