//
// Created by let02 on 2021/12/9.
//
#define PROGRAM_FILE "sha256.cl"
#include "Block.h"
#include "BlockChain.h"
#include "CryptoCL.h"

#include <iostream>

#include <CL/cl.hpp>

int main() {
    //opencl
    //TODO 將cl的部分寫成class
    std::vector<cl::Platform> platforms;
    cl::Platform::get(&platforms);

    if (platforms.empty()) {
        std::cerr << "No platforms!" << std::endl;
        return -1;
    }

    cl::Platform platform = platforms[0];
    std::vector<cl::Device> Devices;

    platform.getDevices(CL_DEVICE_TYPE_GPU, &Devices);
    if (Devices.empty()) {
        std::cerr << "No Devices!" << std::endl;
        return -1;
    }

    cl::Device device = Devices[0];
    std::cout << "Device : " << device.getInfo<CL_DEVICE_NAME>() << std::endl;

    cl::Context context({device});
    cl::Program program(context, PROGRAM_FILE);
    if (program.build() != CL_SUCCESS) { // 編譯程式
        std::cerr << "Fail to build" << std::endl;
        return -1;
    }
    cl::CommandQueue queue(context, device);

    BlockChain bChain = BlockChain();
//    char hash[]="0";
    std::string hash;
    cl::Buffer hashInputBuf(context, CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY, sizeof(string));
    cl::Buffer hashOutputBuf(context, CL_MEM_USE_HOST_PTR | CL_MEM_WRITE_ONLY, sizeof(string));

    cl::Kernel hash_256(program, "hash_main");
    hash_256.setArg(0, hashInputBuf);
    hash_256.setArg(1, hashOutputBuf);

    cout << "Mining block 1 ..." << endl;
    queue.enqueueWriteBuffer(hashInputBuf, CL_FALSE, 0, sizeof(string), bChain.header.data());
    queue.enqueueReadBuffer(hashOutputBuf, CL_FALSE, 0, sizeof(string), (string *)hash.data());
    queue.enqueueNDRangeKernel(hash_256, cl::NullRange,
                               cl::NDRange(100),     // 設定執行緒數目
                               cl::NullRange);
    queue.finish();

    bChain.AddBlock(Block(1, "Block 1 Data"),hash);

    cout << "Mining block 2 ..." << endl;
    queue.enqueueWriteBuffer(hashInputBuf, CL_FALSE, 0, sizeof(string), bChain.header.data());
    queue.enqueueReadBuffer(hashOutputBuf, CL_FALSE, 0, sizeof(string), (string *)hash.data());
    queue.enqueueNDRangeKernel(hash_256, cl::NullRange,
                               cl::NDRange(100),     // 設定執行緒數目
                               cl::NullRange);
    queue.finish();

    bChain.AddBlock(Block(2, "Block 2 Data"), hash);

    cout << "Mining block 3 ..." << endl;
    queue.enqueueWriteBuffer(hashInputBuf, CL_FALSE, 0, sizeof(string), bChain.header.data());
    queue.enqueueReadBuffer(hashOutputBuf, CL_FALSE, 0, sizeof(string), (string *)hash.data());
    queue.enqueueNDRangeKernel(hash_256, cl::NullRange,
                               cl::NDRange(100),     // 設定執行緒數目
                               cl::NullRange);
    queue.finish();

    bChain.AddBlock(Block(3, "Block 3 Data"),hash);

    return 0;
}
