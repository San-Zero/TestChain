//
// Created by let02 on 2021/12/9.
//

#include "BlockChain.h"
#include <iostream>

int main()
{
    Blockchain bChain = Blockchain();

    //cout << "Mining block 1..." << endl;
    //bChain.AddBlock(Block(1, "Block 1 Data"));
    //
    //cout << "Mining block 2..." << endl;
    //bChain.AddBlock(Block(2, "Block 2 Data"));
    //
    //cout << "Mining block 3..." << endl;
    //bChain.AddBlock(Block(3, "Block 3 Data"));

    //cout << "Mining block 4..." << endl;
    //bChain.AddBlock(Block(4, "Block 4 Data"));
    //
    //cout << "Mining block 5..." << endl;
    //bChain.AddBlock(Block(5, "Block 5 Data"));

    int index(0);
    while(index < 50){
        ++index;
        cout << "Mining block "<< index <<"..." << endl;
        bChain.AddBlock(Block(index,"Block test data"));
    }

    return 0;
}
