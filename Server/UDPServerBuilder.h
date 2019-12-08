#pragma once
#include "UDPServer.h"
#include "ServerNotifier.h"
#include "Executer.h"
#include <iostream>
#include <boost/asio/ip/address_v4.hpp>
#include <ifaddrs.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <string.h>

class UDPServer;


class UDPServerBuilder {
private:
    int port;
    boost::asio::ip::address_v4 activeIP;
    ServerNotifier* notifier;
    Executer* executer;

public:
    UDPServerBuilder();
    UDPServerBuilder* setPort(int port);
    UDPServerBuilder* setNotifier(ServerNotifier* notifier);
    UDPServerBuilder* setExecuter(Executer* executer);
    ServerNotifier* getNotifier();
    Executer* getExecuter();
    boost::asio::ip::address_v4 getActiveIP();
    int getPort();

    UDPServer* build();
    
};