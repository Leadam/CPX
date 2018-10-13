cmake_minimum_required(VERSION 3.9.2)

file(GLOB NET_SRC *.cpp)

add_library(net ${CEX_LIBRARY_MODE} ${NET_SRC})