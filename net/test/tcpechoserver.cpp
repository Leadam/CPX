//
// Created by lengyel on 2018.10.24..
//

#include "tcpechoserver.hpp"
#include <iostream>

TcpEchoServer::TcpEchoServer(unsigned int port){
    _socket.setSendTimeout(std::chrono::milliseconds(50));
    _socket.setReceiveTimeout(std::chrono::milliseconds(50));
    _socket.setBlocking(false);
    _socket.listen(port);
}

void TcpEchoServer::_workerThread() {
    while(_isRun){
        try {
            cpx::net::IpAddress addr;
            unsigned int port;
            cpx::net::TcpSocket tcpSocket = _socket.accept(addr, port);
            unsigned char buffer[1024];
            int received = tcpSocket.receive(buffer, 1024);

            tcpSocket.send(buffer, received);
        }catch (std::exception& e){
            //PASS
        }
    }
}

void TcpEchoServer::start(){
    _isRun = true;
    _thread = std::thread(&TcpEchoServer::_workerThread, this);
}

void TcpEchoServer::stop(){
    _isRun = false;
    if(_thread.joinable())
        _thread.join();
}