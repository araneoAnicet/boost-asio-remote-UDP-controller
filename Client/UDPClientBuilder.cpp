#include "UDPClientBuilder.h"

void UDPClientBuilder::setHost() {
    std::cout << "Enter your targer ip:" << std::endl;
    std::cout << ">>> ";
    std::string userInput;
    std::cin >> userInput;
    this->hostAddr = boost::asio::ip::address_v4::from_string(userInput);
}

void UDPClientBuilder::setHost(boost::asio::ip::address_v4 addr) {
    this->hostAddr = addr;
}

void UDPClientBuilder::setPort(int port) {
    this->port = port;
}

boost::asio::ip::address_v4 UDPClientBuilder::getAddress() {
    return this->hostAddr;
}

int UDPClientBuilder::getPort() {
    return this->port;
}

UDPClient* UDPClientBuilder::build() {
    return new UDPClient(this);
}