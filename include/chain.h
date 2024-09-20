#pragma once

#include "transaction.pb.h"
#include "block.pb.h"
#include "util.h"

#include<memory>
#include<mutex>

namespace MiniChain
{

class MiniChain {

public:

    MiniChain() noexcept;

    ~MiniChain()=default;

    void AddBlock(bchain::Block&&);

    int GetLastBlockId(void);

    void RemoveLastBlock(void);

    bool HasTransaction(const bchain::Transaction&);

    std::shared_ptr<bchain::Block> GetBlocksFollowing(int block_id);

    void PrintStateInfo()const;

private:
    int _difficulty{difficulty};
    std::vector<bchain::Transaction> _transactions;
    std::vector<bchain::Block> _blocks;
    std::mutex _mtx;

};

} // namespace minichain