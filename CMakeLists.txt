cmake_minimum_required(VERSION 3.20)
project(TestChain)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(src/include)
include_directories(tools/Fruneng)

#import OPENCL
include_directories(tools/OpenCL)
link_directories(tools/OpenCL/lib/x86)
link_libraries(OpenCL)

configure_file(src/modules/sha256.cl COPYONLY)


add_executable( TestChain src/main.cpp
#                tools/zedwood/sha256.h
#        tools/zedwood/sha256.cpp
#                include/Block.h
                src/modules/Block.cpp
#                include/BlockChain.h
                src/modules/BlockChain.cpp src/include/CryptoCL.h src/modules/CryptoCL.cpp)
target_link_libraries (TestChain OpenCL)
