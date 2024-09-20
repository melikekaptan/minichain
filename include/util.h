
#pragma once

#include "transaction.pb.h"

#include<fmt/format.h>

namespace MiniChain{

#define transaction_send_port 2602
#define transaction_listen_port 2602
#define difficulty 4
#define number_of_transaction_in_block 5
#define genesis_block_id 0


inline void PrintTimestamp(bchain::TimeStamp ts){

            fmt::print("{}-{}-{}  {}:{}:{}\n", ts.year(), ts.month(),
                                                              ts.day(),
                                                              ts.hour(),
                                                              ts.minute(),
                                                              ts.second()
                                                          );
}


}