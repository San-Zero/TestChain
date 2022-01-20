cmake_minimum_required(VERSION 3.20)
project(TestChain)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_VERBOSE_MAKEFILE ON)  #print gcc/g++ detail log

include_directories(src/include)
include_directories(tools/Fruneng)

#import OPENCL
find_package(OpenCL REQUIRED)
#include_directories(tools/OpenCL)
#link_directories(tools/OpenCL/lib/x86)
#link_libraries(OpenCL)

configure_file(tools/Fruneng/sha256.cl sha256.cl COPYONLY)


add_executable( TestChain src/main.cpp
                tools/Fruneng/sha256.c
                src/modules/Block.cpp
                src/modules/BlockChain.cpp
                src/modules/CryptoCL.cpp)
target_link_libraries (TestChain OpenCL::OpenCL)
