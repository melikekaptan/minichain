#include "network.h"

#include <boost/bind/bind.hpp>

namespace MyChain{

#define MODULE_NAME "NETWORK"

Network::Network(::boost::asio::io_context& _io_context, unsigned short port) : _socket(_io_context, boost::asio::ip::udp::endpoint(::boost::asio::ip::udp::v4(),0)), 
                                        _broadcast_endpoint(boost::asio::ip::address_v4::broadcast(), port)
                                        {
                                          boost::system::error_code ec;
                                          _socket.set_option(boost::asio::socket_base::broadcast(true), ec);
                                          
                                          if(ec) {
                                            
                                            std::cerr << ec.message();
                                          }
                                          
                                        }


void Network::SendTransaction(bchain::Transaction &tr){

   
    //boost::asio::streambuf stream_buffer;
    //std::ostream output_stream(&stream_buffer);

    try {

    
      int tr_length = tr.ByteSizeLong();
      std::vector<uint8_t> buf(tr_length);
      std::cout<< buf.size() << '\n';

      if (!tr.SerializeToArray(buf.data(), tr_length)) {
            std::cerr << "Couldn't serialize protobuf" << std::endl;
        }

      //for(const auto& i : buf ) {std::cout << i;}
    
          _socket.async_send_to(boost::asio::buffer(buf.data(), buf.size()), 
                                _broadcast_endpoint,
                                boost::bind(&Network::HandleSend, this,
                                boost::asio::placeholders::error,
                                boost::asio::placeholders::bytes_transferred));
       
    }catch(std::exception &e) {
            fmt::print("not serialised");
     }

}

void Network::HandleSend(const boost::system::error_code& error, std::size_t bytes_transferred){

    std::cout << "AAAAAAAAAAA";
    if(!error) {
      fmt::print("[{}] bytes sent {}/n", MODULE_NAME, bytes_transferred);
    }
    else{
      fmt::print("[{}] error : {} /n", MODULE_NAME, error.message());
    }
}

}