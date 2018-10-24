//
// Created by lengyel on 2018.10.24..
//

#include "socket.hpp"

namespace cpx{
    namespace net{
        Socket::Socket(int af, int type, int protocol) : _socket(new CSocket(af, type, protocol)){
            int use = 1;
            _socket->setSocketOption(SOL_SOCKET,SO_REUSEPORT, &use, sizeof(use));
        }

        Socket::Socket(CSocket::NativeSocket_t socket) : _socket(new CSocket(socket)){
            int use = 1;
            _socket->setSocketOption(SOL_SOCKET,SO_REUSEPORT, &use, sizeof(use));
        }

        Socket::Socket(Socket&& other) noexcept : _socket(std::move(other._socket)) {

        }

        bool Socket::good() const {
            return (bool)_socket;
        }

        void Socket::setSendTimeout(const std::chrono::microseconds &timeout) {
            timeval tv;
            if( timeout <= std::chrono::microseconds(0) )
                tv.tv_sec = tv.tv_usec = 0;
            else
            {
                tv.tv_sec = timeout.count()/1000000;
                tv.tv_usec = timeout.count()%1000000;
            }
            if(_socket->setSocketOption(SOL_SOCKET, SO_SNDTIMEO, &tv, sizeof(tv)) < 0){
                throw std::runtime_error("Unable to set socket send timeout");
            }
        }

        void Socket::setReceiveTimeout(const std::chrono::microseconds &timeout) {
            timeval tv;
            if( timeout <= std::chrono::microseconds(0) )
                tv.tv_sec = tv.tv_usec = 0;
            else
            {
                tv.tv_sec = timeout.count()/1000000;
                tv.tv_usec = timeout.count()%1000000;
            }
            if(_socket->setSocketOption(SOL_SOCKET, SO_RCVTIMEO, &tv, sizeof(tv)) < 0){
                throw std::runtime_error("Unable to set socket receive timeout");
            }
        }


        void Socket::setBlocking(bool mode){
            _socket->setBlocked(mode);
        }

    }
}