cmake_minimum_required(VERSION 3.21)
project(simpleDPI)

set(CMAKE_CXX_STANDARD 17)
#list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_LIST_DIR})
set(AUTO_VCPKG_ROOT /usr/local/vcpkg)
include(autovcpkg.cmake)

vcpkg_install(libtins dataframe)


find_package(libtins CONFIG REQUIRED)
find_package(DataFrame CONFIG REQUIRED)

#find_package(libtins CONFIG REQUIRED)
#find_path(TINS_INCLUDE_DIR tins)
include_directories(${TINS_INCLUDE_DIR})


add_executable(simpleDPI main.cpp)
target_link_libraries(simpleDPI PRIVATE tins pcap DataFrame::DataFrame)

#target_link_libraries(simpleDPI PRIVATE
#        tins)
