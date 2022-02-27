//
// Created by let02 on 2021/12/9.
//
#include "Block.h"
#include "Fruneng/sha256.h"

Block::Block(uint32_t nIndexIn, const string &sDataIn) : _nIndex(nIndexIn), _sData(sDataIn)
{
    _nNonce = 0;
    time(&_tTime);
    sha256_init(2048);
    //sHash = _CalculateHash();
    sHash = "0000000000000000000000000000000000000000000000000000000000000000";
}

//Block::Block(uint32_t nIndexIn, const Transaction &Tx) : _nIndex(nIndexIn), transaction(Tx)
//{
//    _nNonce = 0;
//    time(&_tTime);
//    sha256_init(2048);
//    //sHash = _CalculateHash();
//    sHash = "0000000000000000000000000000000000000000000000000000000000000000";
//    transaction = Tx;
//}

void Block::MineBlock(uint32_t nDifficulty)
{
    char *cstr = new char[nDifficulty + 1];
    for (uint32_t i = 0; i < nDifficulty; ++i)
    {
        cstr[i] = '0';
    }
    cstr[nDifficulty] = '\0';

    string str(cstr);

    clock_t start, end;
    start = clock();

    do
    {
        _nNonce++;
        sHash = _CalculateHash();
    }
    while (sHash.substr(0, nDifficulty) != str);

    end = clock();

    cout << "Block "<< _nIndex << " mined: " << sHash << endl;
    cout << "Timestamp: " << _tTime << endl;
    cout << "Nonce: " << _nNonce << endl;
    cout << "Prev Hash: " << sPrevHash << endl;
    cout << "Computing Time: " << double (end - start) / CLOCKS_PER_SEC << " seconds\n";
    cout << "Speed: " << (uint32_t)_nNonce / (double(end - start) / CLOCKS_PER_SEC )<< "h/s\n";
    cout << "Data: " << _sData << endl;
    cout << "==================================================\n"; // there are 50 of '='

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