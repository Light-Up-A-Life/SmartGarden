#ifndef CLIENTSOCKET_H
#define CLIENTSOCKET_H
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>

#include <nlohmann/json.hpp>
using json = nlohmann::json;

class ClientSocket {
public:
  ClientSocket(std::string addr, int port);
  bool connectC();
  //bool receiveC();
  bool sendC();
  std::string getServerIP() const;
  std::string getPort() const;
  ~ClientSocket();

  json msg_tx = {{"mode", -1}};
  json msg_rx;
  bool isIndrive = false;

private:
  int sock_;
  std::string ip_;
  int port_;
  char buffer_msg_[8192] = {0};
  struct sockaddr_in server_;
};

#endif
