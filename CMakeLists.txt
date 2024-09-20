cmake_minimum_required(VERSION 3.4)

set(CMAKE_C_COMPILER "/usr/bin/clang")
set(CMAKE_CXX_COMPILER "/usr/bin/clang++")

project(minichain)
set(CMAKE_CXX_STANDARD 20)

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -gdwarf-2 -gdwarf-3 -std=c++2a -stdlib=libstdc++")
find_package(Boost)

if(NOT Boost_FOUND)
    message(FATAL_ERROR "Boost Not found")
endif()


ADD_LIBRARY(minichain-lib STATIC src/hash.cpp 
                                  src/transactionBuilder.cpp 
                                  src/transactionListener.cpp
                                  generated/block.pb.cc
                                  generated/transaction.pb.cc 
                                  src/network.cpp
                                  src/transactionListener.cpp
                                  src/minehandler.cpp
                                  src/chain.cpp
                                  src/blockHelper.cpp
                                )

target_include_directories(minichain-lib PUBLIC include generated)

target_link_libraries(minichain-lib -pthread -lssl -lcrypto -lfmt -lprotobuf ${Boost_LIBRARIES} -lboost_system -lboost_thread -lboost_chrono -lboost_context -lboost_coroutine -DBOOST_COROUTINES_NO_DEPRECATION_WARNING
)

add_executable(TEST_transaction test/test_transaction.cpp)
target_link_libraries(TEST_transaction minichain-lib)

add_executable(TEST_sender test/test_sender.cpp)
target_link_libraries(TEST_sender minichain-lib)

add_executable(TEST_transaction_listener test/test_transaction_listener.cpp)
target_link_libraries(TEST_transaction_listener minichain-lib)

add_executable(TEST_mine_handler test/test_mine_handler.cpp)
target_link_libraries(TEST_mine_handler minichain-lib)

add_executable(TEST_bc test/test_minichain.cpp)
target_link_libraries(TEST_bc minichain-lib)