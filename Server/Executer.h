#pragma once
#include <string>

class Executer {
    virtual void execute(std::string receivedMessage) = 0;
};