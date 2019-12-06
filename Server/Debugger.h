#pragma once
#include "ServerNotifier.h"
#include <iostream>
#include <chrono>
#include <ctime>


class Debugger: public ServerNotifier {
public:
    Debugger();
    void notifyMessageSend() override;
    void notifyMessageReceive() override;
    void notifySocketCreated() override;
    void logTime() override;
};