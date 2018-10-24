//
// Created by lengyel on 2018.10.24..
//

#ifndef CPX_TCPECHOSERVER_HPP
#define CPX_TCPECHOSERVER_HPP
#include "../tcpsocket.hpp"
#include <thread>
#include <atomic>

class TcpEchoServer {
private:
    cpx::net::TcpSocket _socket;

    void _workerThread();

    std::thread _thread;
    std::atomic<bool> _isRun;
public:
    explicit TcpEchoServer(unsigned int port);

    void start();

    void stop();
};


#endif //CPX_TCPECHOSERVER_HPP
