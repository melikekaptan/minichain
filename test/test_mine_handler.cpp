
#include"minehandler.h"
#include "util.h"



int main(){

    
try{
    MiniChain::Mine mine{transaction_listen_port};
    
    std::cin.get();
    //using isec = std::chrono::duration<int>;
    //std::this_thread::sleep_for(isec{10});
   // std::cout<<mine.getTransactionCount()<< '\n';
    mine.stop();

    }
        catch(std::exception& e){
            std::cerr << e.what();
}
    
}
