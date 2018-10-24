cmake_minimum_required(VERSION 3.2)

file(GLOB CORE_SRC *.cpp)

add_library(cpx_core ${CPX_LIBRARY_MODE} ${CORE_SRC})