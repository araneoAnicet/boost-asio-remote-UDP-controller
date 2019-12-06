#include "UDPServer.h"


UDPServer::UDPServer() {
    std::cout << "Created UDP server" << std::endl;
}

UDPServer::~UDPServer() {
    std::cout << "Deleting server notifier" << std::endl;
    if (this->notifier != nullptr) {
        delete this->notifier;
    }
}

void UDPServer::setNotifier(ServerNotifier* notifier) {
    this->notifier = notifier;
}

void UDPServer::testServerNotifier() {
    // remove in the future

    if (this->notifier != nullptr) {
        this->notifier->logTime();
        this->notifier->notifyMessageReceive();

        this->notifier->logTime();
        this->notifier->notifyMessageSend();

        this->notifier->logTime();
        this->notifier->notifySocketCreated();
    }
}