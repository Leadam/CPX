//
// Created by lengyel on 2018.10.13..
//
#include <gtest/gtest.h>
#include "../tcpsocket.hpp"
#include "tcpechoserver.hpp"

TEST(TCP, Construct){
    cpx::net::TcpSocket tcp;
}

TEST(TCP, Connect){
    cpx::net::TcpSocket socket;
    TcpEchoServer server(9080);
    server.start();
    socket.connect("127.0.0.1", 9080);
    server.stop();
}

TEST(TCP, SendAndReceive){
    cpx::net::TcpSocket socket;
    TcpEchoServer server(9080);
    server.start();
    socket.connect("127.0.0.1", 9080);

    char data[] = "Hello world";
    char received[1024];

    socket.send(data, sizeof(data));
    socket.receive(received, 1024);

    EXPECT_EQ(std::string(data), std::string(received));

    server.stop();
}

