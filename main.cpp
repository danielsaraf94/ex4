//
#include "ClientHandler.h"
#include "MySerialServer.h"
#include "MyClientHandler.h"
#include "MyTestClientHandler.h"
#include "FileCacheManager.h"
#include "StringReverser.h"
#include "State.h"
#include "StatePriorityQueue.h"

using namespace std;
int main(int argc, char *argv[]) {
/*
  State<string> s1("1");
  s1.setCost(1);
  State<string> s2("2");
  s2.setCost(2);
  State<string> s3("3");
  s3.setCost(3);
  State<string> s4("dan");
  s4.setCost(4);
  State<string> s5("dan");
  s5.setCost(5);

  StatePriorityQueue<string> s;
  s.push(s2);
  s.push(s1);
  s.push(s4);
  s.push(s3);

 cout<<s.contain(s5);
*/
  MySerialServer server;
  StringReverser sr;
  FileCacheManager fcm;
  MyClientHandler ch(&fcm,&sr);
  server.open(atoi(argv[1]),&ch);
  return 0;
}