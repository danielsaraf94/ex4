//
#include "ClientHandler.h"
#include "MySerialServer.h"
#include "MyTestClientHandler.h"
#include "FileCacheManager.h"
#include "StringReverser.h"
using namespace std;
int main(int argc,char* argv[]){
  MySerialServer server;
  StringReverser sr;
  FileCacheManager fcm;
  MyTestClientHandler ch(&fcm,&sr);
  server.open(atoi(argv[1]),&ch);
  return 0;
}