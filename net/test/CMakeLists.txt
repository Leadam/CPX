cmake_minimum_required(VERSION 3.2)

file(GLOB NET_TEST_SRC *.cpp)
set(TEST_NAME cpx_net_test)

include_directories($GTEST_INCLUDE_DIR)

add_executable(${TEST_NAME} ${NET_TEST_SRC})
target_link_libraries(${TEST_NAME}
        cpx_net
        cpx_core
        ${GTEST_LIBRARY}
        ${GTEST_MAIN_LIBRARY}
        ${CMAKE_THREAD_LIBS_INIT}
        )


add_test(NAME ${TEST_NAME} WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR} COMMAND ${TEST_NAME})