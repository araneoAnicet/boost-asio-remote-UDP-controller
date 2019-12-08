#pragma once
#include <iostream>
#include "ServerNotifier.h"
#include "UDPServerBuilder.h"
#include <boost/asio/ip/address_v4.hpp>

class UDPServerBuilder;

class UDPServer {
private:
    ServerNotifier* notifier;
    boost::asio::ip::address_v4 activeIP;
    int port;
public:
    UDPServer(UDPServerBuilder* builder);
    ~UDPServer();
    void testServerNotifier();  // remove in the future
    void setNotifier(ServerNotifier* notifier);
};