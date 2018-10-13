cmake_minimum_required(VERSION 3.2)

file(GLOB NET_TEST_SRC *.cpp)
set(TEST_NAME cpx_net_test)

add_executable(${TEST_NAME} ${NET_TEST_SRC})
target_link_libraries(${TEST_NAME}
        gtest
        gtest_main
        )


add_test(NAME ${TEST_NAME} WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR} COMMAND ${TEST_NAME})