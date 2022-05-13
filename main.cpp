#define TINS_STATIC
#define TINS_HAVE_PCAP
#include <tins/tins.h>
#include <tins/sniffer.h>

int main() {
    const auto interface = Tins::NetworkInterface::default_interface();

    Tins::Sniffer sniffer(interface.name());

    return 0;
}