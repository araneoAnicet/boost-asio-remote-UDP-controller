#include "Debugger.h"

int main() {
    Debugger notifier = Debugger(new UDPServer());
    notifier.notifyMessageReceive();
    notifier.notifyMessageSend();
    notifier.notifySocketCreated();
    return 0;
}