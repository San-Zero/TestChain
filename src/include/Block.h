//
// Created by let02 on 2021/12/9.
//
//TODO 將BlockChain和Block合併，引用CryptoCL做運算
#ifndef TESTCHAIN_BLOCK_H
#define TESTCHAIN_BLOCK_H

#include <cstdint>
#include <iostream>
#include <string>
#include <sstream>

using namespace std;
class Block {
public:

    Block(uint32_t nIndexIn, const string &sDataIn);

    string GetHash();

    string sPrevHash;

    void MineBlock(uint32_t nDifficulty, string hash);

    string getHeader() const{
        std::stringstream ss;
        ss << _nIndex << _tTime << _sData << _nNonce << sPrevHash;

        return ss.str();
    };

private:
    uint32_t _nIndex;
    int64_t _nNonce;
    string _sData;

    string _sHash;

    time_t _tTime;

    string _CalculateHash() const;

    time_t time(void *pVoid);


};
#endif //TESTCHAIN_BLOCK_H

