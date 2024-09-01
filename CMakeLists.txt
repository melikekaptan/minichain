cmake_minimum_required(VERSION 3.4)

set(CMAKE_C_COMPILER "/usr/bin/clang")
set(CMAKE_CXX_COMPILER "/usr/bin/clang++")

project(blockchaindev)

set(CMAKE_CXX_STANDARD 20)

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++2a -stdlib=libstdc++")
find_package(Boost)

if(NOT Boost_FOUND)
    message(FATAL_ERROR "Boost Not found")
endif()



ADD_LIBRARY(blockchain-lib STATIC src/hash.cpp 
                                  src/transactionBuilder.cpp 
                                  src/transactionListener.cpp
                                  generated/transaction.pb.cc 
                                  src/network.cpp
                                  src/transactionListener.cpp
                                  src/mine_handler.cpp
                                )

target_include_directories(blockchain-lib PUBLIC include generated)

target_link_libraries(blockchain-lib -pthread -lssl -lcrypto -lfmt -lprotobuf ${Boost_LIBRARIES} -lboost_system -lboost_thread -lboost_chrono -lboost_context -lboost_coroutine -DBOOST_COROUTINES_NO_DEPRECATION_WARNING
)

add_executable(TEST_transaction test/test_transaction.cpp)
target_link_libraries(TEST_transaction blockchain-lib)

add_executable(TEST_sender test/test_sender.cpp)
target_link_libraries(TEST_sender blockchain-lib)

add_executable(TEST_transaction_listener test/test_transaction_listener.cpp)
target_link_libraries(TEST_transaction_listener blockchain-lib)

add_executable(TEST_mine_handler test/test_mine_handler.cpp)
target_link_libraries(TEST_mine_handler blockchain-lib)
