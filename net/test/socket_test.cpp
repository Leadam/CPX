//
// Created by lengyel on 2018.10.13..
//
#include <gtest/gtest.h>
#include "../socket.hpp"

TEST(Socket, Constructor){ // NOLINT
    cpx::net::Socket socket(AF_INET, SOCK_DGRAM, 0);

    EXPECT_TRUE(socket.good());
}
