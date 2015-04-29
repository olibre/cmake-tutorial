#include <iostream>
#include <map>
#include "parser.h"

using namespace std;

int main(int argc, char* argv[]){
    //cout<<argv[1]<<endl;

    fstream fin(argv[1], ios_base::in|ios_base::binary);
    uint32_t total_packets = 0;
    uint32_t order_entry_msg_count = 0;
    uint32_t order_ack_msg_count = 0;
    uint32_t order_fill_msg_count = 0;
    std::map<string, uint32_t> activeTraderQty;
    std::map<string, uint32_t> GFDs;
    std::map<string, uint32_t> instrumentQty;
    string currentOrderInstrument;
    string currentTrader;

    while (!fin.eof()) {
	Header h;
	Parser::readHeader(h, fin);
	total_packets++;
	uint16_t len = h.msg_len;
	len = len -2 -1 -8 -8 -1 -2;
	if (h.msg_type == 1) { //order entry
	    order_entry_msg_count++;
	    OrderEntry orderEntry;
	    Parser::readOrderEntry(len, fin, orderEntry);
	    if(orderEntry.time_in_force == 2){
		string trader_tag(orderEntry.trader_tag);
		GFDs[trader_tag] += orderEntry.qty;
	    }

	    string instrument(orderEntry.instrument);
	    currentOrderInstrument = instrument;
	    string trader(orderEntry.trader_tag);
	    currentTrader = trader;
	    //printf("%s\n", currentTrader.c_str());

	} else if (h.msg_type == 2) { //order ack
	    order_ack_msg_count++;
	    OrderAck orderAck;
	    Parser::readOrderAck(len, fin , orderAck);
	    
	} else if (h.msg_type == 3) {
	    order_fill_msg_count++;
	    OrderFill orderFill;
	    Parser::readOrderFill(len, fin, orderFill);
	    instrumentQty[currentOrderInstrument] += orderFill.fill_qty;
	    activeTraderQty[currentTrader] += orderFill.fill_qty;
        } else {

	}
    }


    uint32_t maxActiveQty = 0;
    string maxActiveTrader;
    for (std::map<string, uint32_t>::iterator it = activeTraderQty.begin(); it!=activeTraderQty.end(); ++it){
	if (it->second > maxActiveQty){
	    maxActiveQty = it->second;
	    maxActiveTrader = it->first;
	}
    }

    uint32_t maxVol = 0;
    string liquidityTrader;
    for (std::map<string, uint32_t>::iterator it = GFDs.begin(); it!=GFDs.end(); ++it){
	if (it->second > maxVol){
	    maxVol = it->second;
	    liquidityTrader = it->first;
	}
    }

    printf("%u, %u, %u, %u, %s, %s", total_packets, order_entry_msg_count, order_ack_msg_count, order_fill_msg_count, maxActiveTrader.c_str() ,liquidityTrader.c_str());

    for (std::map<string, uint32_t>::iterator it = instrumentQty.begin(); it!=instrumentQty.end(); ++it){
	printf(", %s : %u", it->first.c_str(), it->second);
    }
    printf("\n");
    return 0;
}
