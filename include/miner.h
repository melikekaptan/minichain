#pragma once

#include "transaction.pb.h"

#include <queue>
#include <csignal>
#include <fmt/format.h>
#include <memory>
#include <thread>
#include <functional>



class Mine::Miner{

    public:
        
        Miner();
        void Start();
        void Stop(int parameter);
        
            
private:

    std::function<bchain::Transaction()> _onMine;


}; 