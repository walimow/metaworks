cmake_minimum_required(VERSION 3.4)

project(test)

# Setup testing

enable_testing()

find_package(GTest REQUIRED)

include_directories(${GTEST_INCLUDE_DIR})

add_definitions(-std=c++1z)

# Add test cpp file

add_executable(runUnitTests
        atom_test.cpp
        form_test.cpp info_test.cpp)

set(CMAKE_POSITION_INDEPENDENT_CODE ON)

# Link test executable against gtest & gtest_main

target_link_libraries(runUnitTests ${GTEST_LIBRARY_DEBUG} ${GTEST_MAIN_LIBRARY_DEBUG} pthread) #pthread i had to add (? -k.h.)

#target_link_libraries(runUnitTests ${GTEST_LIBRARY} ${GTEST_MAIN_LIBRARY} pthread ) #pthread i had to add (? -k.h.)

##target_link_libraries(runUnitTests gtest  pthread )

add_test(

        NAME runUnitTests

        COMMAND runUnitTests

)

 
