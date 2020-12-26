cmake_minimum_required(VERSION 3.4)
project(metaworks)

set(CMAKE_CXX_STANDARD 20)


include_directories(
        ./include
        ${STEPWORKS_INCLUDE}
)

set(MW_INCLUDES include/metaworks.hpp include/trace.hpp include/defines.hpp include/apply.hpp include/forms.hpp include/info.hpp include/namesq.hpp)

add_subdirectory(test)

add_executable(metaworks main.cpp ${MW_INCLUDES})