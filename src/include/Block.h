//
// Created by let02 on 2021/12/9.
//
//TODO 將BlockChain和Block合併，引用CryptoCL做運算
#ifndef TESTCHAIN_BLOCK_H
#define TESTCHAIN_BLOCK_H

#include <cstdint>
#include <iostream>
#include <sstream>

using namespace std;

class Block {
public:
    string sHash;
    string sPrevHash;

    Block(uint32_t nIndexIn, const string &sDataIn);

    void MineBlock(uint32_t nDifficulty);

private:
    uint32_t _nIndex;
    uint32_t _nNonce;
    string _sData;
    time_t _tTime;

    string _CalculateHash() const;

    time_t time(void *pVoid);
};
#endif //TESTCHAIN_BLOCK_H

