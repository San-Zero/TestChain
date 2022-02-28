//
// Created by let02 on 2022/2/15.
//

#ifndef TESTCHAIN_TRANSACTION_H
#define TESTCHAIN_TRANSACTION_H

#include <string>
#include <cstdint>
#include <sstream>

#include "zedwood/sha256.h"

class Transaction {
public:
    Transaction(const std::string &sender, const std::string &receiver, double amount,
                             double fee, const std::string &message);
    std::string getTransaction();
private:
    std::string sender_;
    std::string receiver_;
    double amount_;
    double fee_;
    std::string message_;
    int sequence = 0;
};

#endif //TESTCHAIN_TRANSACTION_H
