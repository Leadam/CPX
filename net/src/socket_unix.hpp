//
// Created by lengyel on 2018.10.13..
//

#ifndef CEX_SOCKET_UNIX_HPP
#define CEX_SOCKET_UNIX_HPP
#include <memory>
#include <sys/socket.h>
#include <unistd.h>
#include <stdexcept>
#include <fcntl.h>

namespace cpx {
    namespace net {
        class Socket {
        public:
            typedef int NativeSocket_t;
            typedef std::shared_ptr<Socket> ptr_t;
        private:
            static const int INVALID_SOCKET = -1;
            NativeSocket_t _socket;
        public:

            explicit Socket(NativeSocket_t socket) : _socket(socket) {}

            Socket(int af, int type, int protocol) : _socket(::socket(af,type,protocol)){}

            inline NativeSocket_t accept(struct sockaddr *address, socklen_t *address_len) {
                return ::accept(_socket, address, address_len);
            }

            inline int bind(const struct sockaddr *address, socklen_t address_len) {
                return ::bind(_socket, address, address_len);
            }

            inline int connect(const struct sockaddr *address, socklen_t address_len) {
                return ::connect(_socket, address, address_len);
            }

            inline int getPeerName(struct sockaddr *address, socklen_t *address_len) {
                return ::getpeername(_socket, address, address_len);
            }

            inline int getSocketName(struct sockaddr *address, socklen_t *address_len) {
                return ::getsockname(_socket, address, address_len);
            }

            inline int getSockOpt(int level, int option_name, void *option_value, socklen_t *option_len) {
                return ::getsockopt(_socket, level, option_name, option_value, option_len);
            }

            inline int listen(int backlog) {
                return ::listen(_socket, backlog);
            }

            inline ssize_t recive(void *buffer, size_t length, int flags) {
                return ::recv(_socket, buffer, length, flags);
            }

            inline ssize_t reciveFrom(void *buffer, size_t length, int flags, struct sockaddr *address, socklen_t *address_len) {
                return ::recvfrom(_socket, buffer, length, flags, address, address_len);
            }

            inline ssize_t reciveMessage(struct msghdr *message, int flags) {
                return ::recvmsg(_socket, message, flags);
            }

            inline ssize_t send(const void *message, size_t length, int flags) {
                return ::send(_socket, message, length, flags);
            }

            inline ssize_t sendMessage(const struct msghdr *message, int flags) {
                return ::sendmsg(_socket, message, flags);
            }

            inline ssize_t sendTo(const void *message, size_t length, int flags, const struct sockaddr *dest_addr,
                                  socklen_t dest_len) {
                return ::sendto(_socket, message, length, flags, dest_addr, dest_len);
            }

            inline int setSocketOption(int level, int option_name, const void *option_value, socklen_t option_len) {
                return ::setsockopt(_socket, level, option_name, option_value, option_len);
            }

            inline int shutdown(int how) {
                return ::shutdown(_socket, how);
            }

            inline void close() {
                ::close(_socket);
            }

            void setBlocked(bool blocked){
                long arg;
                if((arg = fcntl(_socket, F_GETFL, NULL)) < 0)
                    throw std::runtime_error("Can not set socket blocking mode");

                if(blocked)
                    arg &= ~O_NONBLOCK; // NOLINT
                else
                    arg |= O_NONBLOCK; // NOLINT

                if(fcntl(_socket, F_SETFL, arg) < 0)
                    throw std::runtime_error("Can not set socket blocking mode");

            }

            virtual ~Socket(){
                close();
            }
        };
    }
}

#endif //CEX_SOCKET_UNIX_HPP