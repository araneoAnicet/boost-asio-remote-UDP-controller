#include "Debugger.h"

Debugger::Debugger(UDPServer udp_server) {
    this->setUDPServer(udp_server);
}

void Debugger::setUDPServer(UDPServer udp_server) {
    this->setUDPServer = udp_server;
}

void Debugger::notifyMessageSend() {
    this->logTime();
    std::cout << "Sent a message" << std::endl;
}

void Debugger::notifyMessageReceive() {
    this->logTime();
    std::cout << "Received a new message" << std::endl;
}

void Debugger::notifySocketCreated() {
    this->logTime();
    std::cout << "Socket created" << std::endl;
}

void Debugger::logTime() {
    std::time_t currentTime = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
    std::cout << std::ctime << "\t";
}

void Debugger::logNotificationTime(void (*func)(void)) {
    this->logTime();
    func();
}