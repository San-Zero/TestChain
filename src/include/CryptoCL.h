//
// Created by let02 on 2022/1/6.
//

#ifndef TESTCHAIN_CRYPTOCL_H
#define TESTCHAIN_CRYPTOCL_H

#include <cstdint>
#include <iostream>

#ifdef __APPLE__
#include <OpenCL/opencl.hpp>
#else
#include <CL/cl.hpp>
#endif

#define MAX_SOURCE_SIZE 0x10000000

class Crypto{
public:
    Crypto(uint32_t platform, uint32_t id);
private:
    void load_source();
};
#endif //TESTCHAIN_CRYPTOCL_H
