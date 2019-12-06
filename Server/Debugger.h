#pragma once
#include "ServerNotifier.h"
#include <iostream>
#include <chrono>
#include <ctime>


class Debugger: public ServerNotifier {
public:
    Debugger(UDPServer udp_server);
    void setUDPServer(UDPServer udp_server) override;
    void notifyMessageSend() override;
    void notifyMessageReceive() override;
    void notifySocketCreated() override;
    void logTime();
    void logNotificationTime(void (*func)(void));
};