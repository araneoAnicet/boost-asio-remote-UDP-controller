#include "MessagePrinter.h"

void MessagePrinter::execute(std::string receivedMessage) {
    std::cout << "Received message from host:\t" << receivedMessage << std::endl;
}