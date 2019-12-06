#include "UDPServer.h"


UDPServer::UDPServer() {
    std::cout << "Created UDP server" << std::endl;
}

UDPServer::~UDPServer() {
    std::cout << "Deleting server notifier" << std::endl;
    delete this->notifier;
}

void UDPServer::setNotifier(ServerNotifier* notifier) {
    this->notifier = notifier;
}

void UDPServer::testServerNotifier() {
    this->notifier->notifyMessageReceive();
    this->notifier->notifyMessageSend();
    this->notifier->notifySocketCreated();
}