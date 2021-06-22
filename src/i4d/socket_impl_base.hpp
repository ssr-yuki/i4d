/*********************************************************************
 * Copyright 2021 Yuki Onishi
 *
 * This software is released under the MIT license.
 * http://opensource.org/licenses/mit-license.php
 *********************************************************************/
#ifndef I4D_SOCKET_IMPL_BASE_HPP_
#define I4D_SOCKET_IMPL_BASE_HPP_

#include <memory>
#include <string>
#include <vector>

#include <cstdint>

namespace i4d {

class SocketImplBase {

public:
  SocketImplBase();
  ~SocketImplBase();

protected:
  int16_t socket_;
};

} // namespace i4d

#endif // I4D_SOCKET_IMPL_BASE_HPP_
