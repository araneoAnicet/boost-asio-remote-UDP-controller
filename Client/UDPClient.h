#pragma once
#include "UDPClientBuilder.h"
#include <boost/asio/ip/address_v4.hpp>

class UDPClientBuilder;

class UDPClient {
private:
    boost::asio::ip::address_v4 address;
    int port;

public:
    UDPClient(UDPClientBuilder* builder);
};