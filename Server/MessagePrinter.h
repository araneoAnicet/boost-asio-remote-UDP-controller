#pragma once
#include "Executer.h"
#include <iostream>

class MessagePrinter: public Executer {
    void execute(std::string receivedMessage) override;
};