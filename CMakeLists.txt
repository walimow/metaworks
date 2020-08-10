cmake_minimum_required(VERSION 3.16)
project(metaworks)

set(CMAKE_CXX_STANDARD 20)


include_directories(
        ./include
        ${STEPWORKS_INCLUDES}
)


add_subdirectory(test)

add_executable(metaworks main.cpp include/metaworks.hpp include/trace.hpp include/defines.hpp include/apply.hpp)