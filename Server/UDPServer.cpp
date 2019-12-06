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
    // remove in the future
    this->notifier->logTime();
    this->notifier->notifyMessageReceive();

    this->notifier->logTime();
    this->notifier->notifyMessageSend();

    this->notifier->logTime();
    this->notifier->notifySocketCreated();
}