#include "Debugger.h"

Debugger::Debugger() {
    std::cout << "Created Debugger" << std::endl;
}

void Debugger::notifyMessageSend() {
    std::cout << "Sent a message" << std::endl;
}

void Debugger::notifyMessageReceive() {
    std::cout << "Received a new message" << std::endl;
}

void Debugger::notifySocketCreated() {
    std::cout << "Socket created" << std::endl;
}

void Debugger::logTime() {
    std::time_t currentTime = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
    std::cout << std::endl << std::ctime(&currentTime) << "\t";
}

