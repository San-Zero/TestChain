//
// Created by let02 on 2022/2/21.
//

#include "Transaction.h"

Transaction::Transaction(const std::string &sender, const std::string &receiver, double amount,
                         double fee, const std::string &message) {
    sender_ = sender;
    receiver_ = receiver;
    amount_ = amount;
    fee_ = fee;
    message_ = message;
}

std::string Transaction::getTransaction() {
    std::stringstream ss;
    ss.str("");
    ss << sender_ << receiver_ << amount_ << fee_ << message_;

    return ss.str();
}
