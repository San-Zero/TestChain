//
// Created by let02 on 2021/12/9.
//

#include "BlockChain.h"

#include <string>

BlockChain::BlockChain(){
    Block block = Block(0, "Genesis Block");
    _vChain.emplace_back(block);
    _nDifficulty = 6;
}

void BlockChain::AddBlock(Block bNew, string hash) {
    bNew.sPrevHash = _GetLastBlock().GetHash();
    bNew.MineBlock(_nDifficulty, hash);
    _vChain.push_back(bNew);
    header = bNew.getHeader();
}

Block BlockChain::_GetLastBlock() const {
    return _vChain.back();
}

//string BlockChain::GetBlockHeader(Block header) const {
//    return header.getHeader();
//}
