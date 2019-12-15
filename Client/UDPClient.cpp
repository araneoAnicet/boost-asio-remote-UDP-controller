#include "UDPClient.h"

UDPClient::UDPClient(UDPClientBuilder* builder) {
    this->address = builder->getAddress();
    this->port = builder->getPort();
}