#pragma once
#include <string>

class Executer {
public:
    virtual void execute(std::string receivedMessage) = 0;
};