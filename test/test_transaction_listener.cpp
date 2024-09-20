#include "transactionListener.h"
#include "util.h"
#include "transaction.pb.h"

#include <iostream>



int main() {


try{
    //TransactionListener tr_listener{transaction_listen_port, [](bchain::Transaction){std::cout<<"onReceive called";}};

    //tr_listener.run();
    std::cin.get();


    //tr_listener.quit();
    //using isec = std::chrono::duration<int>;
    //std::this_thread::sleep_for(isec{10});

    //tr_listener.~TransactionListener();

    //using isec = std::chrono::duration<int>;
    //std::this_thread::sleep_for(isec{10});
    }
        catch(std::exception& e){
            std::cerr << e.what();
}
}
