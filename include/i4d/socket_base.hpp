/*********************************************************************
 * Copyright 2021 Yuki Onishi
 *
 * This software is released under the MIT license.
 * http://opensource.org/licenses/mit-license.php
 *********************************************************************/
#ifndef I4D_SOCKET_BASE_HPP_
#define I4D_SOCKET_BASE_HPP_

#include <memory>
#include <string>
#include <vector>

namespace i4d {

class SocketImplBase;

class SocketBase {
 public:
  SocketBase();
  ~SocketBase();

 protected:
  std::unique_ptr<SocketImplBase> impl_;
};

}  // namespace i4d

#endif  // I4D_SOCKET_BASE_HPP_
