//
// Created by let02 on 2021/12/9.
//

//TODO: 將BlockChain.h 和 Block.h 整合為一個 header file
#ifndef TESTCHAIN_BLOCKCHAIN_H
#define TESTCHAIN_BLOCKCHAIN_H

#include <cstdint>
#include <vector>
#include "Block.h"
#include "Transaction.h"

using namespace std;

class Blockchain {
public:
    Blockchain();

    void AddBlock(Block bNew);

private:
    uint32_t _nDifficulty;
    vector<Block> _vChain;

    Block _GetLastBlock() const;
};
#endif //TESTCHAIN_BLOCKCHAIN_H

