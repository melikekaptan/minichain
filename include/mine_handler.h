#pragma once

#include "transaction.pb.h"
#include "transactionListener.h"

#include<queue>
#include<memory>
#include<mutex>
#include<condition_variable>

namespace MiniChain{

class Mine{

public:

    Mine(unsigned short transaction_listner_port);

    ~Mine();

    void addTransaction(bchain::Transaction tr);

    bchain::Transaction popTransaction();

    unsigned short getTransactionListnerPort()const;

    int getTransactionCount()const;

    void stop();
    
private:
    unsigned short tr_listener_port;
    TransactionListener _transaction_listener{tr_listener_port, std::bind(&Mine::addTransaction, this, std::placeholders::_1)}; //transaction to be copied

    std::queue<bchain::Transaction> _transaction_queue;
    std::mutex _mtx;
    class Miner;
    std::unique_ptr<Miner> _miner{nullptr};
    std::condition_variable _cv;
    std::mutex miner_mutex;
};
}