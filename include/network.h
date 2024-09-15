#pragma once

#include "transaction.pb.h"

#include <boost/asio.hpp>
#include <boost/asio/streambuf.hpp>
#include <boost/asio/basic_socket.hpp>


namespace MiniChain{

class Network{

public:

    Network(::boost::asio::io_context& _io_context, unsigned short port);
    void SendTransaction(bchain::Transaction &tr);

    
    void HandleSend(const boost::system::error_code& error, std::size_t bytes_transferred);


private:
    
    ::boost::asio::ip::udp::socket _socket;
    ::boost::asio::ip::udp::endpoint _broadcast_endpoint;

};

}

