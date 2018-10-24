//
// Created by lengyel on 2018.10.13..
//

#include "tcpsocket.hpp"
#include "../core/except.hpp"
#include <netinet/in.h>
#include <cstring>

namespace cpx {
    namespace net {

        TcpSocket::TcpSocket() : Socket(AF_INET, SOCK_STREAM, 0) {

        }

        TcpSocket::TcpSocket(CSocket::NativeSocket_t socket) : Socket(socket){

        }

        TcpSocket::TcpSocket(TcpSocket&& other) noexcept : Socket(std::move(other)){

        }

        void TcpSocket::listen(unsigned int port, unsigned int backlog){
            if(!_socket) throw std::runtime_error("Socket not exist");
            sockaddr_in addr; //NOLINT
            addr.sin_family = AF_INET;
            addr.sin_addr.s_addr = INADDR_ANY;
            addr.sin_port = htons(port);
            std::memset(&addr.sin_zero, 0, sizeof(addr.sin_zero));
            if(_socket->bind((sockaddr*)&addr, sizeof(addr))){
                throwErrno<cpx::network_error>();
            }
            if(_socket->listen(backlog)){
                throwErrno<cpx::network_error>();
            }
        }

        void TcpSocket::connect(const IpAddress &address, unsigned int port) {
            if(!_socket) throw std::runtime_error("Socket not exist");
            sockaddr_in addr; //NOLINT
            addr.sin_family = AF_INET;
            addr.sin_addr.s_addr = *reinterpret_cast<const unsigned int*>(&address);
            addr.sin_port = htons(port);
            std::memset(&addr.sin_zero, 0, sizeof(addr.sin_zero));
            if(_socket->connect((sockaddr*)&addr, sizeof(addr))){
                throwErrno<cpx::network_error>();
            }
        }

        TcpSocket TcpSocket::accept() const {
            if(!_socket) throw std::runtime_error("Socket not exist");
            CSocket::NativeSocket_t clinet = _socket->accept(nullptr,nullptr);
            if(clinet < 0) throwErrno<cpx::network_error>();
            return TcpSocket(clinet);
        }

        TcpSocket TcpSocket::accept(cpx::net::IpAddress &address, unsigned int& port) const {
            if(!_socket) throw std::runtime_error("Socket not exist");
            sockaddr_in addr;
            socklen_t len;
            CSocket::NativeSocket_t client = _socket->accept((sockaddr*)&addr, &len);
            if(client < 0) throwErrno<cpx::network_error>();
            address = IpAddress (*reinterpret_cast<unsigned int*>(&addr.sin_addr.s_addr));
            port = ntohs(addr.sin_port);
            return TcpSocket(client);
        }

        size_t TcpSocket::send(const void *data, size_t size, int flag) {
            if(!_socket) throw std::runtime_error("Socket not exist");
            int ret = _socket->send(data, size, flag);
            if(ret < 0) throwErrno<cpx::network_error>();
            return ret;
        }

        size_t TcpSocket::receive(void *data, size_t size, int flag){
            if(!_socket) throw std::runtime_error("Socket not exist");
            int ret = _socket->recive(data, size, flag);
            if(ret < 0) {
                if (errno == ETIMEDOUT)
                    throwErrno<cpx::timeout>();
                throwErrno<cpx::network_error>();
            }
            return ret;
        }

        void TcpSocket::shutdown(int mode){
            if(!_socket) throw std::runtime_error("Socket not exist");
            if(_socket->shutdown(mode)){
                throwErrno<cpx::network_error>();
            }
        }
    }
}