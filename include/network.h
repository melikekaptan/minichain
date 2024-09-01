#pragma once

#include "transaction.pb.h"

#include <boost/asio.hpp>
#include <boost/asio/streambuf.hpp>
#include <boost/asio/basic_socket.hpp>
#include <boost/asio/awaitable.hpp>
#include <boost/asio/use_awaitable.hpp>
#include <fmt/format.h>
#include "google/protobuf/io/coded_stream.h"
#include "google/protobuf/io/zero_copy_stream_impl.h"

namespace MyChain{

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

