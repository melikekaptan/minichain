#pragma once

#include "transaction.pb.h"

#include <boost/asio.hpp>
#include <boost/array.hpp>

namespace MiniChain{

class TransactionListener{

    public:
  
    TransactionListener(unsigned short port, std::function<void(bchain::Transaction)> receiveCallback);
    ~TransactionListener();
    //TransactionListener(const TransactionListener& other) = delete;
    void run(void);
    void quit(void);
 
    void handle_receive(const boost::system::error_code & err,
                        const std::size_t bytes);
                  

    private:
    boost::asio::io_context _io_context;
    boost::asio::ip::udp::socket _socket;
    boost::asio::ip::udp::endpoint _broadcast_endpoint;
    boost::array<char, 1024> _receive_buf;
    std::thread _io_thread;
    std::function<void(bchain::Transaction)> _onReceive;
    std::atomic<bool> _is_running;
};
}
