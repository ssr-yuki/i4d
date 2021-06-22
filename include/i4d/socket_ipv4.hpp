/*********************************************************************
 * Copyright 2021 Yuki Onishi
 *
 * This software is released under the MIT license.
 * http://opensource.org/licenses/mit-license.php
 *********************************************************************/
#ifndef I4D_SOCKET_IPV4_HPP_
#define I4D_SOCKET_IPV4_HPP_

#include "i4d/socket_base.hpp"

#include <memory>
#include <string>
#include <vector>

#include <cstdint>

namespace i4d {

class SocketIPv4 : public SocketBase {
 public:
  SocketIPv4();
  ~SocketIPv4();

  void tryConnect(const std::string &ip, const uint16_t port_number);

 protected:
  class Impl;
  std::unique_ptr<Impl> impl_;
};

}  // namespace i4d

#endif  // I4D_SOCKET_IPV4_HPP_
