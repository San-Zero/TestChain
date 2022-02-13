//
// Created by let02 on 2021/12/9.
//
#include "Block.h"
#include "Fruneng/sha256.h"

Block::Block(uint32_t nIndexIn, const string &sDataIn) : _nIndex(nIndexIn), _sData(sDataIn)
{
    _nNonce = 0;
    time(&_tTime);

    //TODO:
    sha256_init(2048);


    sHash = _CalculateHash();

}

void Block::MineBlock(uint32_t nDifficulty)
{
    clock_t start, stop;
    start = clock();

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

    stop = clock();
    cout << "Block mined: " << sHash << "\n";
    cout << "Time: " << double (stop - start)/CLOCKS_PER_SEC << "s\n";
    delete [] cstr;
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
    return string(result);
}