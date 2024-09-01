#include "transactionBuilder.h"

namespace MyChain{

TransactionBuilder::TransactionBuilder(std::string key, std::string data, std::string publicKey){

    TransactionBuilder::_transaction.set_publickey(publicKey.c_str());
    TransactionBuilder::_transaction.set_data(data.c_str());
    TransactionBuilder::_transaction.set_signature(rsa::signMessage(key,data));
    auto timeStamp = std::chrono::system_clock::now();
    const std::time_t t_c = std::chrono::system_clock::to_time_t(timeStamp);
    auto gmtime = std::gmtime(&t_c);
    //std::cout << std::put_time(gmtime, "%F %T.\n") << std::flush;
    ::bchain::TimeStamp* timestamp_now = new ::bchain::TimeStamp();
    //bchain::Transaction_TimeStamp timestamp_now;

    timestamp_now->set_year(gmtime->tm_year + 1900);
    timestamp_now->set_month(gmtime->tm_mon+1);
    timestamp_now->set_day(gmtime->tm_mday);
    timestamp_now->set_hour(gmtime->tm_hour);
    timestamp_now->set_minute(gmtime->tm_min);
    timestamp_now->set_second(gmtime->tm_sec);


    TransactionBuilder::_transaction.set_allocated_timestamp(timestamp_now);

    TransactionBuilder::_key = key;

    //delete timestamp_now;
}



void TransactionBuilder::representTransaction(){

    
   // std::cout << std::put_time(gmtime, "%F %T.\n") << std::flush;
   
    if(true == TransactionBuilder::_transaction.has_timestamp()){
        
        
        fmt::print("transaction at {}-{}-{}  {}:{}:{}\n", TransactionBuilder::_transaction.timestamp().year(),
                                                          TransactionBuilder::_transaction.timestamp().month(),
                                                          TransactionBuilder::_transaction.timestamp().day(),
                                                          TransactionBuilder::_transaction.timestamp().hour(),
                                                          TransactionBuilder::_transaction.timestamp().minute(),
                                                          TransactionBuilder::_transaction.timestamp().second()
                                                          );
                              
    }
    else{
        fmt::print("no timestamp");
    }
     
}

}