/*********************************************************************
 * Copyright 2021 Yuki Onishi
 *
 * This software is released under the MIT license.
 * http://opensource.org/licenses/mit-license.php
 *********************************************************************/
#include "i4d/socket_base.hpp"
#include "i4d/socket_impl_base.hpp"

#include <memory>
#include <string>
#include <vector>

#include <cstdint>
#include <cstring>

#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>

namespace i4d {

SocketBase::SocketBase() : impl_{new SocketImplBase()} {}

SocketImplBase::SocketImplBase() : socket_{0} {}

SocketBase::~SocketBase() {}

SocketImplBase::~SocketImplBase() {}

}  // namespace i4d
