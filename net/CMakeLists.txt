cmake_minimum_required(VERSION 3.2)

file(GLOB NET_SRC *.cpp)

add_library(cpx_net ${CPX_LIBRARY_MODE} ${NET_SRC})

target_link_libraries(cpx_net cpx_core)