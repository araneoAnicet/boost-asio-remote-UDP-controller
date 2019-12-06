#pragma once
#include "UDPServer.h"

class ServerNotifier {
protected:
    UDPServer* udp_server;
public:
    virtual void setUDPServer(UDPServer* udp_server) = 0;
    virtual void notifyMessageSend() = 0;
    virtual void notifyMessageReceive() = 0;
    virtual void notifySocketCreated() = 0;

};
