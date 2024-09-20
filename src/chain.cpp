#include "chain.h"
#include "blockHelper.h"

#include<algorithm>
#include<exception>
#include<fmt/format.h>

namespace MiniChain{

    MiniChain::MiniChain()noexcept{}


    void MiniChain::AddBlock(bchain::Block&& block){

        auto moved_block = std::move(block);
        if(_blocks.empty()){
            block.set_id(genesis_block_id);
            _blocks.push_back(block);
            return;
        }

        if (GetLastBlockId() != block.previous_block_id())
            throw std::runtime_error("refused to add new block");

        for(const auto& tr : block.transactionlist()){
            if(HasTransaction(tr)){
                throw std::runtime_error("refused to add new block");
            }
        }
        _blocks.push_back(block);
    }

    int MiniChain::GetLastBlockId(void){
        if(_blocks.empty()){return 0;}
        return _blocks.back().id();
    }

    void MiniChain::RemoveLastBlock(void){

        std::scoped_lock slock(_mtx);
        //auto last_block = _blocks.end();
        _blocks.pop_back();

    }

   // std::shared_ptr<bchain::Block> MiniChain::GetBlocksFollowing(int block_id){

     //   auto it = std::find_if(_blocks.rbegin(), _blocks.rend(), [this, block_id](const auto& bl){
       //                                             return bl.id() == block_id;
         //                                               }); 
        //return *(it.base()-1);      
    //}



    bool MiniChain::HasTransaction(const bchain::Transaction& tr){
        auto res =  std::find_if(_blocks.begin(), _blocks.end(), [this, &tr](auto& b){
                                                            return BlockHelper{b}.HasTransaction(tr);
                                                             });

        return false;
    }

    void MiniChain::PrintStateInfo()const {

        for(const auto &bl : _blocks){
            fmt::print("{} : {} : {} : {}", bl.id(), bl.proof(), bl.previous_hash(), bl.previous_block_id());
            PrintTimestamp(bl.timestamp());
        }
    }

}