#include "UDPServer.h"


UDPServer::UDPServer(UDPServerBuilder* builder) {
    this->notifier = builder->getNotifier();
    this->activeIP = builder->getActiveIP();
    this->port = builder->getPort();
    this->executer = builder->getExecuter();
}

UDPServer::~UDPServer() {
    std::cout << "Deleting server notifier" << std::endl;
    delete this->notifier;

    std::cout << "Deleting server executer" << std::endl;
    delete this->executer;
}

void UDPServer::setNotifier(ServerNotifier* notifier) {
    this->notifier = notifier;
}

void UDPServer::setExecuter(Executer* executer) {
    this->executer = executer;
}

void UDPServer::testServerNotifier() {
    // remove in the future

    this->notifier->logTime();
    this->notifier->notifyMessageReceive();

    this->notifier->logTime();
    this->notifier->notifyMessageSend();

    this->notifier->logTime();
    this->notifier->notifySocketCreated();
}

void UDPServer::testExecuter(std::string message) {
    // remove in the future

    this->executer->execute(message);
}

void UDPServer::run() {
    boost::asio::io_service io_service;
    
    boost::asio::ip::udp::socket socket(
        io_service,
        boost::asio::ip::udp::endpoint(this->activeIP, this->port)
        );

    while (true) {
        boost::array<char, BUFFER_SIZE> bufferArray;
        boost::asio::ip::udp::endpoint remoteEndpoint;
        boost::system::error_code error;

        size_t bytesReceived;
        socket.receive_from(boost::asio::buffer(bufferArray), remoteEndpoint, 0, error);
        this->executer->execute(boost::asio::buffer_cast<const char*>(boost::asio::buffer(bufferArray))); 
    }

}