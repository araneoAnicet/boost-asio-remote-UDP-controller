#pragma once
#include <iostream>
#include "ServerNotifier.h"
#include "UDPServerBuilder.h"
#include <boost/asio/ip/address_v4.hpp>
#include "Executer.h"


class UDPServerBuilder;

class UDPServer {
private:
    ServerNotifier* notifier;
    Executer* executer;
    boost::asio::ip::address_v4 activeIP;
    int port;
public:
    UDPServer(UDPServerBuilder* builder);
    ~UDPServer();
    void testServerNotifier();  // remove in the future
    void testExecuter(std::string message);  // remove in the future
    void setNotifier(ServerNotifier* notifier);
    void setExecuter(Executer* executer);
};