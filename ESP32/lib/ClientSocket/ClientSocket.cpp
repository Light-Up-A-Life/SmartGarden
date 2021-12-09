#include "ClientSocket.h"

ClientSocket::ClientSocket(std::string addr, int port)
: ip_(addr), port_(port) {}

bool ClientSocket::connectC()
{
  if ((sock_ = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
    return false;
  }
  server_.sin_addr.s_addr = inet_addr(ip_.c_str());
  server_.sin_family = AF_INET;
  server_.sin_port = htons(port_);
  if (connect(sock_, (struct sockaddr *)&server_, sizeof(server_)) < 0) {
    return false;
  }
  return true;
}
/*
bool ClientSocket::receiveC()
{
  int bytes_rcv = recv(sock_, buffer_msg_, sizeof(buffer_msg_), 0);
  if (bytes_rcv <= 0) {
    return false;
  }
  RCLCPP_DEBUG(rclcpp::get_logger("StradotHardware"), "bytes recv %d", bytes_rcv);
  RCLCPP_DEBUG(rclcpp::get_logger("StradotHardware"), " msg rx %s", buffer_msg_);
  msg_rx = json::parse(buffer_msg_);
  isIndrive = msg_rx["isInDrive"];
  std::memset(buffer_msg_, 0, sizeof(buffer_msg_));
  return true;
}
*/
bool ClientSocket::sendC()
{
  std::string s = msg_tx.dump();
  std::string size_msg = std::to_string(s.size());
  size_msg = std::string(4 - size_msg.length(), '0') + size_msg;
  send(sock_, size_msg.c_str(), size_msg.size(), 0);
  send(sock_, s.c_str(), s.size(), 0);
  return true;
}

std::string ClientSocket::getServerIP() const {return ip_;}

std::string ClientSocket::getPort() const {return std::to_string(port_);}

ClientSocket::~ClientSocket() {close(sock_);}
