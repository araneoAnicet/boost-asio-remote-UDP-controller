#pragma once
#include <iostream>
#include "ServerNotifier.h"
#include "UDPServerBuilder.h"
#include <boost/asio.hpp>
#include <boost/array.hpp>
#include <boost/asio/ip/address_v4.hpp>
#include "Executer.h"

#define BUFFER_SIZE 1024


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
    void run();
    void setNotifier(ServerNotifier* notifier);
    void setExecuter(Executer* executer);
};