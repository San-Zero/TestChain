cmake_minimum_required(VERSION 3.20)
project(TestChain)

set(CMAKE_CXX_STANDARD 14)

add_executable(TestChain src/main.cpp include/Block.h include/BlockChain.h tools/zedwood/sha256.cpp tools/zedwood/sha256.h src/module/Block.cpp src/module/BlockChain.cpp)
