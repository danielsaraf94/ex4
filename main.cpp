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
  fcm.saveSolution("hello1", "world1");
  fcm.saveSolution("hello2", "world2");
  fcm.saveSolution("hello3", "world3");
  fcm.saveSolution("hello4", "world3");
  fcm.saveSolution("hello5", "world3");
  fcm.saveSolution("hello6", "world6");
  string s = fcm.getSolution("hello1");
  cout<<s<<endl;
  s=s = fcm.getSolution("hello3");
  cout<<s<<endl;
  MyTestClientHandler ch(&fcm,&sr);
  server.open(atoi(argv[1]),&ch);
  return 0;
}