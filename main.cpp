//
#include "ClientHandler.h"
#include "MySerialServer.h"
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
  MyParallelServer server;
  ObjectAdapter sr(new BreadthFirstSearch<Point>());
  FileCacheManager fcm;
  MyClientHandler ch(&fcm, &sr);
  server.open(atoi(argv[1]), &ch);
  return 0;

}