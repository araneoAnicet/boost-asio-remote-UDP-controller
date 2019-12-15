#pragma once
#include "UDPClient.h"
#include <boost/asio/ip/address_v4.hpp>

class UDPClient;

class UDPClientBuilder {
private:
    boost::asio::ip::address_v4 hostAddr;
    int port;

public:
    UDPClientBuilder();
    void setHost();
    void setHost(boost::asio::ip::address_v4 host);
    void setPort(int port);
    UDPClient* build();
};