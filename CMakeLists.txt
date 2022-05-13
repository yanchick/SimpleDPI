cmake_minimum_required(VERSION 3.21)
project(simpleDPI)

set(CMAKE_CXX_STANDARD 14)
#list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_LIST_DIR})
#include(autovcpkg.cmake)

#vcpkg_install(libtins)


find_package(libtins CONFIG REQUIRED)


#find_package(libtins CONFIG REQUIRED)
#find_path(TINS_INCLUDE_DIR tins)
include_directories(${TINS_INCLUDE_DIR})


add_executable(simpleDPI main.cpp)
target_link_libraries(simpleDPI PRIVATE tins)
target_link_libraries(simpleDPI PRIVATE pcap)

#target_link_libraries(simpleDPI PRIVATE
#        tins)
