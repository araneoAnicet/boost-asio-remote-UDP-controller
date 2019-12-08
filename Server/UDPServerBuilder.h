#pragma once
#include "UDPServer.h"
#include <iostream>
#include "boost/asio.hpp"
#include <ifaddrs.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <string.h>



class UDPServerBuilder {
private:
    int port;
    boost::asio::ip::address_v4 activeIP;
    ServerNotifier* notifier = nullptr;


public:
    UDPServerBuilder();
    UDPServerBuilder* setPort(int port);
    UDPServerBuilder* setNotifier(ServerNotifier* notifier);
    ServerNotifier* getNotifier();
    boost::asio::ip::address_v4 getActiveIP();
    int getPort();

    UDPServer* build();
    
};