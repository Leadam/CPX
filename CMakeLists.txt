cmake_minimum_required(VERSION 3.2)
project(CPX)

set (CMAKE_CXX_STANDARD 11)

option(CPX_ENABLE_TEST "Enable library test" ON)
if(CPX_ENABLE_TEST)
#    find_package(GTEST)
endif()


option(CPX_ENABLE_NET "Enable network extension library" ON)
set(CPX_NET_DIR "net/src")
set(CPX_NET_TEST_DIR "net/test")


if(CPX_ENABLE_NET)
    add_subdirectory(${CPX_NET_DIR})
    if(CPX_ENABLE_TEST)
        add_subdirectory(${CPX_NET_TEST_DIR})
    endif()
endif()




option(CPX_ENABLE_STATIC "Enable static library" ON)
if(CPX_ENABLE_STATIC)
    set(CPX_LIBRARY_MODE STATIC)
else(CPX_ENABLE_STATIC)
    set(CPX_LIBRARY_MODE SHARED)
endif()