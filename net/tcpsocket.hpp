//
// Created by lengyel on 2018.10.13..
//

#ifndef CPX_TCPSOCKET_HPP
#define CPX_TCPSOCKET_HPP
#include "socket.hpp"
#include "ip.hpp"

namespace cpx{
    namespace net{
        class TcpSocket : public Socket{
        protected:
            explicit TcpSocket(CSocket::NativeSocket_t socket);
        public:
            TcpSocket();

            TcpSocket(TcpSocket&& other) noexcept;

            void listen(unsigned int port, unsigned int backlog = 5);

            void connect(const IpAddress& address, unsigned int port);

            TcpSocket accept()const;

            TcpSocket accept(IpAddress& address, unsigned int& port)const;

            size_t send(const void* data, size_t size, int flag = 0);

            size_t receive(void *data, size_t size, int flag = 0);

            void shutdown(int mode = 0);
        };
    }
}

#endif //CPX_TCPSOCKET_HPP
