#pragma once
#include <iostream>
#include "ServerNotifier.h"


class UDPServer {
private:
    ServerNotifier* notifier;
public:
    UDPServer();
    ~UDPServer();
    void testServerNotifier();
    void setNotifier(ServerNotifier* notifier);
};