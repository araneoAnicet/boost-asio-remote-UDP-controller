#include "UDPServer.h"


UDPServer::UDPServer(UDPServerBuilder* builder) {
    this->notifier = builder->getNotifier();
    this->activeIP = builder->getActiveIP();
    this->port = builder->getPort();
}

UDPServer::~UDPServer() {
    std::cout << "Deleting server notifier" << std::endl;
    delete this->notifier;
}

void UDPServer::setNotifier(ServerNotifier* notifier) {
    this->notifier = notifier;
}

void UDPServer::setExecuter(Executer* executer) {
    this->executer = executer;
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