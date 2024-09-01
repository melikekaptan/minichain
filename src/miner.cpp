#include "miner.h"

#define MODULE_NAME "MINER"



    Miner::Miner(){
        fmt::print("[{}] started ", MODULE_NAME);
    }

    void Miner::Start(){
            
        try{
            
        std::function<void(bchain::Transaction&)> my_function = [](auto new_transaction){
             _transaction_queue.push(new_transaction);
        };
       TransactionListener::_event = 1;
        _transactionListener= std::make_unique<TransactionListener>(2601, my_function);
            
        std::raise(SIGINT);
       
        }
        catch(std::exception &e)
        {
        fmt::print("cannot raise miner: {}", e.what());
        }
        
    }


    void Miner::run(int parameter){
    
        thr = _transactionListener->member1Thread();
        //thr.join();
    }
    void Miner::Stop(int parameter){
        thr.join();
        fmt::print("{}: Stop called", MODULE_NAME);
        std::signal(SIGTERM, Miner::abort);
        std::raise(SIGTERM);
    }
