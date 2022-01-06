//
// Created by let02 on 2021/12/9.
//
#include "Block.h"
#include "sha256.h"

Block::Block(uint32_t nIndexIn, const string &sDataIn) : _nIndex(nIndexIn), _sData(sDataIn)
{
    _nNonce = 0;
    _tTime = time(nullptr);

    sHash = _CalculateHash();

    sha256_init(2048);
}

void Block::MineBlock(uint32_t nDifficulty)
{
    char *cstr = new char[nDifficulty + 1];
    for (uint32_t i = 0; i < nDifficulty; ++i)
    {
        cstr[i] = '0';
    }
    cstr[nDifficulty] = '\0';

    string str(cstr);

    do
    {
        _nNonce++;
        sHash = _CalculateHash();
    }
    while (sHash.substr(0, nDifficulty) != str);

    cout << "Block mined: " << sHash << endl;
    delete [] cstr;
}

string Block::_CalculateHash() const
{
    stringstream ss;
    ss.str("");
    ss << _nIndex << sPrevHash << _tTime << _sData << _nNonce;
    const char *input = ss.str().c_str();
    char result[65];
    sha256_crypt(input, result);

    ss.clear();
    return string(result);
}

time_t Block::time(void *pVoid) {
    return 0;
}

