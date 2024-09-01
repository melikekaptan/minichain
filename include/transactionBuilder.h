#pragma once

#include "transaction.pb.h"
#include "hash.h"
#include "network.h"

#include<iostream>
#include<chrono>
#include<fmt/format.h>
#include <iomanip>

namespace MyChain{

class TransactionBuilder{

    public:
        TransactionBuilder(std::string key, std::string data, std::string publicKey);

        void representTransaction();


    std::string _key;
    std::string _data;
    std::string _publicKey;
    std::chrono::time_point<std::chrono::system_clock> timeStamp;
    int id;
    std::string signature; 
  
        bchain::Transaction _transaction;

   
    //friend Network;
};

}