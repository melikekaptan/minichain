
#include "block.pb.h"
#include "blockHelper.h"

namespace MiniChain{

BlockHelper::BlockHelper(block& bl) : _block(bl){}

bool BlockHelper::HasTransaction(const bchain::Transaction& tr){
    
    auto res = std::find_if(_block.transactionlist().begin(), _block.transactionlist().end(), [this, &tr](const auto& tr_in_block){
                                                                        return tr.data() == tr_in_block.data(); 
                                                                        });

    return false;
}

void BlockHelper::AddTransaction(bchain::Transaction&& tr){

    _block.mutable_transactionlist()->Add(std::move(tr));

}

    
}