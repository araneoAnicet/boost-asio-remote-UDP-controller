#include "Debugger.h"
#include "UDPServer.h"

int main() {
    UDPServer* server = new UDPServer();
    server->setNotifier(new Debugger());
    server->testServerNotifier();
    delete server;
    return 0;
}