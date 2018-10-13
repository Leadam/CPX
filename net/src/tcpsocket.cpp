//
// Created by lengyel on 2018.10.13..
//

#include "tcpsocket.hpp"
#include <netinet/in.h>
#include <cstring>

namespace cpx {
    namespace net {

        TcpSocket::TcpSocket() : _socket(std::make_shared<Socket>(AF_INET, SOCK_STREAM, 0)) {}

        void TcpSocket::connect(const IpAddress &address, unsigned int port) {
            sockaddr_in addr; //NOLINT
            addr.sin_family = AF_INET;
            addr.sin_addr.s_addr = *reinterpret_cast<const unsigned int*>(&address);
            addr.sin_port = htonl(port);
            std::memset(addr.sin_zero, 0, sizeof(addr.sin_zero));
            _socket->connect((sockaddr*)&addr, sizeof(addr));
        }
    }
}