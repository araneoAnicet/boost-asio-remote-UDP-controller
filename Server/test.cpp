#include "UDPServerBuilder.h"
#include "UDPServer.h"
#include "Debugger.h"

int main() {
    UDPServer* server = (new UDPServerBuilder())->setNotifier(new Debugger())->setPort(9090)->build();
    server->testServerNotifier();
    delete server;
    return 0;
}