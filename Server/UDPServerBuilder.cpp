#include "UDPServerBuilder.h"



UDPServerBuilder::UDPServerBuilder() {
    using namespace boost;

    struct ifaddrs *ifap, *ifa;
    struct sockaddr_in* sa;
    char* addr;

    getifaddrs (&ifap);
    for (ifa = ifap; ifa; ifa = ifa->ifa_next) {
        if (ifa->ifa_addr && ifa->ifa_addr->sa_family == AF_INET && strcmp(ifa->ifa_name, "lo") != 0) {
            sa = (struct sockaddr_in *) ifa->ifa_addr;
            addr = inet_ntoa(sa->sin_addr);
            this->activeIP = asio::ip::address_v4::from_string(addr);
            std::cout << "Got interface ip: " << activeIP.to_string() << std::endl;
        }
    }

    freeifaddrs(ifap);
}


UDPServerBuilder* UDPServerBuilder::setPort(int port) {
    this->port = port;
    return this;
}

UDPServerBuilder* UDPServerBuilder::setNotifier(ServerNotifier* notifier) {
    this->notifier = notifier;
    return this;
}

UDPServerBuilder* UDPServerBuilder::setExecuter(Executer* executer) {
    this->executer = executer;
    return this;
}

ServerNotifier* UDPServerBuilder::getNotifier() {
    return this->notifier;
}

boost::asio::ip::address_v4 UDPServerBuilder::getActiveIP() {
    return this->activeIP;
}

int UDPServerBuilder::getPort() {
    return this->port;
}

Executer* UDPServerBuilder::getExecuter() {
    return this->executer;
}

UDPServer* UDPServerBuilder::build() {
    return new UDPServer(this);
}