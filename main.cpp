using namespace std;
#include "MySerialServer.h"
#include "MyTestClientHandler.h"
int main() {

  MySerialServer s;
  s.open(5400);
  while(true){}
  return 0;
}
