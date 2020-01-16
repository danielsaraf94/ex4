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
int main(int argc, char *argv[]) {
/*
  unordered_map<State<Point>, int> g_score;
  State<Point> sss(Point(2,3));
  State<Point> ds(Point(2,3));
  g_score[ds]=1;
  cout <<  g_score[sss] << endl;
  cout << (g_score.find(sss) == g_score.end()) << endl;
*/
  MyParallelServer server;
  Searcher<Point, vector<State<Point>>> *s = new AStar<Point>();
  ObjectAdapter sr(s);
  FileCacheManager fcm;
  MyClientHandler ch(&fcm, &sr);
  server.open(atoi(argv[1]), &ch);
  return 0;
}