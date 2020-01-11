#include "MySerialServer.h"
void MySerialServer::open(int port,ClientHandler* client_handler) {
  //bind socket to IP address
  // we first need to create the sockaddr obj.
  sockaddr_in address; //in means IP4
  address.sin_family = AF_INET;
  address.sin_addr.s_addr = INADDR_ANY; //give me any IP allocated for my machine
  address.sin_port = htons(port);
  //we need to convert our number
  // to a number that the network understands.
  //the actual bind command
  if (bind(this->socketfd, (struct sockaddr *) &address, sizeof(address)) == -1) {
    cerr << "Could not bind the socket to an IP" << endl;
    exit(1);
  }
  //making socket listen to the port
  if (listen(this->socketfd, 5) == -1) { //can also set to SOMAXCON (max connections)
    cerr << "Error during listening command" << endl;
    exit(1);
  } else {
    cout << "waiting for client to connect" << endl;
  }
  thread t(start, socketfd, address,client_handler);
  t.detach();
}

void MySerialServer::start(int socketfd, sockaddr_in address,ClientHandler* client_handler) {
  int client_socket;
  while(true) {
    client_socket = accept(socketfd, (struct sockaddr *) &address, (socklen_t *) &address);
    if (client_socket == -1) {
      cerr << "error accepting client" << endl;
      exit(1);
    }
    cout << "client connected" << endl;
    client_handler->handleClient(client_socket);
  }
}
void MySerialServer::stop() {

}
