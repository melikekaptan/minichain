#pragma once

#include "transaction.pb.h"
#include "block.pb.h"

class Block {

    Block();

    void AddTransaction(bchain::Transaction);

    bool IsTransactionAlreadyInThisBlock(bchain::Transaction);

};