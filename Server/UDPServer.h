#pragma once
#include <iostream>
#include "ServerNotifier.h"


class UDPServer {
private:
    ServerNotifier* notifier = nullptr;
public:
    UDPServer();
    ~UDPServer();
    void testServerNotifier();  // remove in the future
    void setNotifier(ServerNotifier* notifier);
};