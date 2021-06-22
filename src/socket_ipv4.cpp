/*********************************************************************
 * Copyright 2021 Yuki Onishi
 *
 * This software is released under the MIT license.
 * http://opensource.org/licenses/mit-license.php
 *********************************************************************/
#include "i4d/socket_ipv4.hpp"
#include "i4d/socket_base.hpp"
#include "i4d/socket_impl_base.hpp"

#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>

#include <memory>
#include <string>
#include <system_error>
#include <vector>

#include <cerrno>
#include <cstdint>
#include <cstring>

namespace i4d {

class SocketIPv4::Impl : public SocketImplBase {
 public:
  Impl();

  void tryConnect(const std::string &ip, const uint16_t port_number);

 private:
  struct sockaddr_in destination_;  // for IPv4
};

SocketIPv4::SocketIPv4() : impl_{new SocketIPv4::Impl()} {}

SocketIPv4::Impl::Impl() : SocketImplBase() {
  std::memset(&destination_, 0, sizeof(destination_));
}

void SocketIPv4::tryConnect(const std::string &ip, const uint16_t port_number) {
  impl_->tryConnect(ip, port_number);
  return;
}

void SocketIPv4::Impl::tryConnect(const std::string &ip,
                                  const uint16_t port_number) {
  destination_.sin_addr.s_addr = inet_addr(ip.data());
  destination_.sin_family = AF_INET;  // IPv4 protocol family
  destination_.sin_port = htons(port_number);

  socket_ = socket(destination_.sin_family, SOCK_STREAM, 0);

  if (connect(socket_, reinterpret_cast<const sockaddr *>(&destination_),
              sizeof(destination_)) == -1) {
    socket_ = 0;
    throw std::system_error(std::error_code(errno, std::generic_category()),
                            std::strerror(errno));
  }

  return;
}

}  // namespace i4d
