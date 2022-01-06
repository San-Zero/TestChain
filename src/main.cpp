//
// Created by let02 on 2021/12/9.
//
#define PROGRAM_FILE "sha256.cl"

#include "BlockChain.h"
#include "CryptoCL.h"

#include <iostream>

#include <CL/cl.hpp>

int main()
{
    std::cout<<"1\n";
    Blockchain bChain = Blockchain();
    std::cout<<"2\n";
    cout << "Mining block 1..." << endl;
    bChain.AddBlock(Block(1, "Block 1 Data"));
    std::cout<<"3\n";
    cout << "Mining block 2..." << endl;
    bChain.AddBlock(Block(2, "Block 2 Data"));
    std::cout<<"4\n";
    cout << "Mining block 3..." << endl;
    bChain.AddBlock(Block(3, "Block 3 Data"));

    return 0;
}
