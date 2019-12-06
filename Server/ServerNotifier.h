#pragma once

class ServerNotifier {
public:
    virtual void notifyMessageSend() = 0;
    virtual void notifyMessageReceive() = 0;
    virtual void notifySocketCreated() = 0;
    virtual void logTime() = 0;
};
