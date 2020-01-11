//
// Created by daniels on 11/01/2020.
//

#ifndef EX4_5__BOOT_H_
#define EX4_5__BOOT_H_
#include "ClientHandler.h"
#include "MySerialServer.h"
#include "MyTestClientHandler.h"
#include "FileCacheManager.h"
#include "StringReverser.h"
using namespace std;
namespace boot{
class Main{
 public:
  int main(int argc,char* argv[]){
    MySerialServer server;
    StringReverser sr;
    FileCacheManager fcm;
    MyTestClientHandler ch(&fcm,&sr);
    server.open(atoi(argv[argc]),&ch);
    return 0;
  }
};
}
#endif //EX4_5__BOOT_H_
