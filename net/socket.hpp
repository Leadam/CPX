//
// Created by lengyel on 2018.10.13..
//

#ifndef CPX_SOCKET_HPP
#define CPX_SOCKET_HPP

#ifdef __linux__
#include "socket_unix.hpp"
#endif
#include <chrono>

namespace cpx{
    namespace net{
        class Socket{
        protected:
            CSocket::ptr_t _socket;

            explicit Socket(CSocket::NativeSocket_t socket);
        public:
            Socket(int af, int type, int protocol);

            Socket(Socket&& other) noexcept;

            bool good()const;

            void setSendTimeout(const std::chrono::microseconds& timeout);

            void setReceiveTimeout(const std::chrono::microseconds& timeout);

            void setBlocking(bool mode);
        };
    }
}

#endif //CPX_SOCKET_HPP
