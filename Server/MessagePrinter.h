#pragma once
#include "Executer.h"
#include <iostream>

class MessagePrinter: public Executer {
public:
    void execute(std::string receivedMessage) override;
};