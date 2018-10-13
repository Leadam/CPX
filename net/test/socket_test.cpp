//
// Created by lengyel on 2018.10.13..
//
#include <gtest/gtest.h>
#include "../src/socket.hpp"

TEST(Socket, Constructor){ // NOLINT
    cpx::net::Socket Sokcet(AF_INET, SOCK_DGRAM, 0);
}
