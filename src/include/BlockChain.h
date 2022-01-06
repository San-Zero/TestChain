//
// Created by let02 on 2021/12/9.
//

#ifndef TESTCHAIN_BLOCKCHAIN_H
#define TESTCHAIN_BLOCKCHAIN_H

#include "Block.h"

#include <cstdint>
#include <vector>
#include <string>

using namespace std;
class BlockChain {
public:
    BlockChain();

    void AddBlock(Block bNew, string hash);

    std::string header;

private:

    uint32_t _nDifficulty;
    vector<Block> _vChain;


    Block _GetLastBlock() const;
};
#endif //TESTCHAIN_BLOCKCHAIN_H

