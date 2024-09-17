
#include "transactionListener.h"
#include "transaction.pb.h"

#include<fmt/format.h>
#include <boost/asio/basic_socket.hpp>
#include <thread>

namespace MiniChain{

#define MODULE_NAME "TRANSACTION_LISTENER"

TransactionListener::TransactionListener(unsigned short port, std::function<void(bchain::Transaction)> receiveCallback) : _io_context{}, _socket{_io_context, boost::asio::ip::udp::endpoint(::boost::asio::ip::udp::v4(), port)}, 
                                                                _onReceive{receiveCallback},
                                                                _is_running(true) {
        
        fmt::print("[{}] started \n", MODULE_NAME);
        boost::system::error_code ec;
        _socket.set_option(boost::asio::ip::udp::socket::reuse_address(true), ec);
        if (ec) {
            fmt::print("[{}] error in socket option {} \n", MODULE_NAME, ec.message());
        }

        run();

        _io_thread = std::thread([this](){_io_context.run();
                            });
     
    };

TransactionListener::~TransactionListener(){

    std::cout<< "drstuctor called";
    quit();
}

void TransactionListener::run(){

    fmt::print("[{}] running \n", MODULE_NAME);

    try{

        _socket.async_receive_from(boost::asio::buffer(_receive_buf), _broadcast_endpoint,
                                    [this](const boost::system::error_code& error, std::size_t bytes_transferred) {
                                    handle_receive(error, bytes_transferred);
                                });

    }
    catch(std::exception &e)
    {
        fmt::print("[{}] read error: {} \n", MODULE_NAME, e.what());
    }
}

void TransactionListener::handle_receive(const boost::system::error_code& err, const std::size_t bytes){
    try{ 
        if (!err && _is_running) {
            //std::cout << "Received message: " << std::string(receive_buf.data(), bytes)
             //         << " from " << _broadcast_endpoint<< std::endl;

            //std::cout << "received size: " << bytes<< '\n';
            bchain::Transaction tr{};

            //tr.ParseFromCodedStream(received_buf.data());
            if(tr.ParseFromArray(_receive_buf.data(), bytes)){

                fmt::print("{} : {} - {} - {} \n",tr.id(), tr.timestamp().year(), tr.timestamp().month(), tr.timestamp().day());
                _onReceive(tr);
            }
            fmt::print("transaction from {}", tr.GetTypeName());

            // Start another asynchronous receive operation
            run();
        } else if (err) {
            std::cerr << "Error on receive: " << err.message() << std::endl;
        }
        
    }
    catch(std::exception &e)
    {
        fmt::print("[{}] handle receive error: {} \n", MODULE_NAME, e.what());
    }                       
}

void TransactionListener::quit(){
   

    if (_is_running.exchange(false)) {
            // Stop the io_context
            _io_context.stop();

            // Close the socket gracefully
            if (_socket.is_open()) {
                boost::system::error_code ec;
                _socket.close(ec);
                if (ec) {
                    fmt::print("[{}] error closing the port  {} \n", MODULE_NAME, ec.message());
                }
            }

            // Join the io_context thread
            if (_io_thread.joinable()) {
                _io_thread.join();
            }

            fmt::print("[{}] stopped  \n", MODULE_NAME);
        }

}
}
