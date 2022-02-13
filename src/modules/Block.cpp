//
// Created by let02 on 2021/12/9.
//
#include "Block.h"
#include "Fruneng/sha256.h"

Block::Block(uint32_t nIndexIn, const string &sDataIn) : _nIndex(nIndexIn), _sData(sDataIn)
{
    _nNonce = 0;
    time(&_tTime);
    //TODO: 每次呼叫BLock時，都會重新做一次sha256_init()， 要新增釋放opencl配置的記憶體
    sha256_init(2048);
    sHash = _CalculateHash();
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
    cout << "Nonce: " << _nNonce << endl;

    delete [] cstr;
    clRelease();
}

string Block::_CalculateHash() const
{
    stringstream ss;
    ss.str("");
    ss << _nIndex << sPrevHash << _tTime << _sData << _nNonce;
    std::string input(ss.str());
    //const char *crypto_input = input.c_str();

    char* char_input = const_cast<char*>(input.c_str());
    char result[65] = "";
    sha256_crypt(char_input, result);

    ss.clear();
    //cout << result << '\n';
    return string(result);
}