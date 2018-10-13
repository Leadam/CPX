//
// Created by lengyel on 2018.10.13..
//

#ifndef CPX_TCPSOCKET_HPP
#define CPX_TCPSOCKET_HPP
#include "socket.hpp"
#include "ip.hpp"

namespace cpx{
    namespace net{
        class TcpSocket {
        private:
            Socket::ptr_t _socket;
        public:
            TcpSocket();

            void connect(const IpAddress& address, unsigned int port);
        };
    }
}

#endif //CPX_TCPSOCKET_HPP
