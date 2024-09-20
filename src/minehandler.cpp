
#include"minehandler.h"
#include "util.h"
#include "hash.h"
#include "chain.h"
#include "blockHelper.h"

#include<fmt/format.h>

#define MODULE_NAME "MINE_HANDLER"


namespace MiniChain{

class Mine::Miner{

public:
        
    Miner(Mine& mine_handler): _mine_handler{mine_handler}, _difficulty{difficulty}, transaction_count{number_of_transaction_in_block}, _is_running(true){

        mine_thread = std::thread([this](){Perform();
                            });
    }
    
    void Stop(){
        if (_is_running.exchange(false)) {
            fmt::print("[MINER] quitting the mining \n");
            _mine_handler._cv.notify_one();
            if(mine_thread.joinable()){
                std::cout << "before join";
                mine_thread.join();
                std::cout << "after join" ;
            }

            else{ fmt::print(" ERROR :could not join the miner thread ");}
          fmt::print("[MINER] stopped  \n");
        }
        //else{ fmt::print(" ERROR!!!! ");}

         //fmt::print(" STOP ");
        
    }

    void Perform();

    ~Miner(){
    
       Stop();
    }
 
    std::function<bchain::Transaction()> _onMine;
    Mine& _mine_handler;
    int _difficulty{};
    int transaction_count{};
    std::atomic<bool> _is_running;
    std::thread mine_thread;
}; 



    //bool is_running(){return }
void Mine::Miner::Perform() {

        while(_is_running){
            fmt::print("[MINER] waits for queue to be filled \n");
            std::unique_lock<std::mutex> ulock(_mine_handler.miner_mutex);
            _mine_handler._cv.wait(ulock, [this](){ return (!_is_running || _mine_handler.getTransactionCount() >= number_of_transaction_in_block);});

            if(!_is_running) { break; }
          
            auto current_unmined_block = bchain::Block();
            current_unmined_block.set_previous_block_id(_mine_handler._minichain.GetLastBlockId());

            for(int i{}; i < number_of_transaction_in_block; ++i){
                auto tr = _mine_handler.popTransaction();
                  if(!rsa::verifySignature(tr.publickey(), tr.data(), tr.signature().c_str())){
                    fmt::print("[{}] signaure cannot verified \n", MODULE_NAME);
                    continue;}
                    try{
                    
                         BlockHelper{current_unmined_block}.AddTransaction(std::move(tr));
                    }
                    catch(std::exception& e){
                        std::cerr << e.what();}
                

            }
            _mine_handler._minichain.AddBlock(std::move(current_unmined_block));
           //current_unmined_block = {};
            fmt::print("[MINER] queue consumed enough \n");
            _mine_handler._minichain.PrintStateInfo();
    }
       
}

Mine::Mine(unsigned short transaction_listner_port): tr_listener_port{transaction_listner_port}, _miner{new Miner{*this}} {}

     

Mine::~Mine(){
    stop();

}


unsigned short Mine::getTransactionListnerPort()const{
        return tr_listener_port;
    }

void Mine::addTransaction(bchain::Transaction tr){

    std::scoped_lock<std::mutex> lg(_mtx);
    _transaction_queue.push(tr);
        fmt::print("[{}] {} \n", MODULE_NAME,_transaction_queue.size());
        if(_transaction_queue.size() >= number_of_transaction_in_block) {
            _cv.notify_one();
        }
    }

bchain::Transaction Mine::popTransaction(){
    std::scoped_lock<std::mutex> lg(_mtx);

    bchain::Transaction tr = _transaction_queue.front();
    _transaction_queue.pop();
    return tr;
}


int Mine::getTransactionCount()const{
    return _transaction_queue.size();
}

void Mine::stop(){
    fmt::print("[{}] quiting transaction listening \n", MODULE_NAME);
    _transaction_listener.quit();
    fmt::print("[{}] quiting miner \n", MODULE_NAME);
    _miner->Stop();
    fmt::print("[{}] quited miner \n", MODULE_NAME);
    }

}//Mychain
    