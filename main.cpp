using namespace std;
#include "MySerialServer.h"
#include "MyTestClientHandler.h"
#include "StringReverser.h"
#include "FileCacheManager.h"
int main() {

  MySerialServer server;
  StringReverser sr;
  FileCacheManager fcm;
  MyTestClientHandler ch(&fcm,&sr);

  server.open(5400,&ch);
  while(true){}
  return 0;
}
