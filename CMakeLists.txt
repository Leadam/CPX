cmake_minimum_required(VERSION 3.2)
project(CPX)

set (CMAKE_CXX_STANDARD 11)

option(CPX_ENABLE_COVERAGE "Enable code coverage check" ON)
if(CPX_ENABLE_COVERAGE)
    set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} --coverage -fprofile-arcs -ftest-coverage)
endif()

option(CPX_ENABLE_TEST "Enable library test" ON)
if(CPX_ENABLE_TEST)
    find_package(GTest REQUIRED)
    find_package (Threads REQUIRED)
endif()


set(CPX_CORE_DIR "core")
set(CPX_CORE_TEST_DIR "${CPX_CORE_DIR}/test")

option(CPX_ENABLE_NET "Enable network extension library" ON)
set(CPX_NET_DIR "net")
set(CPX_NET_TEST_DIR "${CPX_NET_DIR}/test")

if(CPX_ENDABLE_TEST)
    enable_testing()
endif()

add_subdirectory(${CPX_CORE_DIR})
if(CPX_ENABLE_TEST)
    add_subdirectory(${CPX_CORE_TEST_DIR})
endif()

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

option(CPX_ENABLE_PACK "Enable CMakePackage" ON)
if(CPX_ENABLE_PACK)
    include (InstallRequiredSystemLibraries)
    set (CPACK_RESOURCE_FILE_LICENSE
            "${CMAKE_CURRENT_SOURCE_DIR}/LICENSE")
    set (CPACK_PACKAGE_VERSION_MAJOR "${Tutorial_VERSION_MAJOR}")
    set (CPACK_PACKAGE_VERSION_MINOR "${Tutorial_VERSION_MINOR}")
    include (CPack)
endif()