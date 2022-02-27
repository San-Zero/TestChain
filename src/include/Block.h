//
// Created by let02 on 2021/12/9.
//
#ifndef TESTCHAIN_BLOCK_H
#define TESTCHAIN_BLOCK_H

#include <cstdint>
#include <iostream>
#include <sstream>
#include <ctime>
#include <vector>

#include "Transaction.h"

using namespace std;

class Block {
public:
    string sHash;
    string sPrevHash;

    Block(uint32_t nIndexIn, const string &sDataIn);

    Block(uint32_t nIndexIn, const Transaction &Tx);

    void MineBlock(uint32_t nDifficulty);

private:
    uint32_t _nIndex;
    uint32_t _nNonce;
    string _sData;
    time_t _tTime;
    //Transaction transaction;

    string _CalculateHash() const;
};

#endif //TESTCHAIN_BLOCK_H

