//
// Created by daniels on 11/01/2020.
//
#ifndef EX4_5__BOOT_H_
#define EX4_5__BOOT_H_
#include "MySerialServer.h"
#include "MyTestClientHandler.h"
#include "StringReverser.h"
#include "FileCacheManager.h"
using namespace std;
namespace boot {
  int main(int argc, char *argv[]) {
    MySerialServer server;
    StringReverser sr;
    FileCacheManager fcm;
    MyTestClientHandler ch(&fcm, &sr);
    server.open(atoi(argv[argc]), &ch);
    while (true) {}
    return 0;
  }
}

#endif //EX4_5__BOOT_H_
