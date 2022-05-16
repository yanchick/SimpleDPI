#include <tins/tins.h>
#include <tins/sniffer.h>
#include <tins/ip.h>
#include <iostream>
#include <DataFrame/DataFrame.h>
#include <DataFrame/DataFrameStatsVisitors.h>
#include <thread>

using ULDataFrame = hmdf::StdDataFrame<unsigned long>;



void portListner(){
    const auto interface = Tins::NetworkInterface::default_interface();
    Tins::SnifferConfiguration config;
    config.set_filter("tcp");
    config.set_promisc_mode(true);
    Tins::Sniffer sniffer(interface.name(),config);
    for (auto &packet : sniffer) {
        auto p = packet.pdu();
        std::stringstream s;
        std::cout << "At: " << packet.timestamp().seconds()
                  << " - " << packet.pdu()->rfind_pdu<Tins::IP>().src_addr()
                  << " - " << packet.pdu()->rfind_pdu<Tins::IP>().dst_addr()
                  << std::endl;
        auto i=0;
    }


}

int main() {
    std::thread t(portListner);
    t.join();
    return 0;
}