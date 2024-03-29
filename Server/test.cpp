#include "UDPServerBuilder.h"
#include "UDPServer.h"
#include "Debugger.h"
#include "MessagePrinter.h"

int main() {
    UDPServer* server = (new UDPServerBuilder())
        ->setNotifier(new Debugger())
        ->setPort(9090)
        ->setExecuter(new MessagePrinter())
        ->build();
    server->run();
    delete server;
    return 0;
}