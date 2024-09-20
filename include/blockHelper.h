#pragma once

#include "block.pb.h"

namespace MiniChain{


    using block = bchain::Block;

    class BlockHelper{
    public:

        BlockHelper(block&);

        bool HasTransaction(const bchain::Transaction&);

        void AddTransaction(bchain::Transaction&&);

    private:

        block& _block;

    };


}