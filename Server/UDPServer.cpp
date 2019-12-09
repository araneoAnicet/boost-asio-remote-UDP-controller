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

void UDPServer::run() {
    boost::asio::io_service io_service;
    
    boost::asio::ip::udp::socket socket(
        io_service,
        boost::asio::ip::udp::endpoint(this->activeIP, this->port)
        );
    this->notifier->notifySocketCreated();
    while (true) {
        boost::array<char, BUFFER_SIZE>* bufferArray = new boost::array<char, BUFFER_SIZE>();
        boost::asio::ip::udp::endpoint remoteEndpoint;
        boost::system::error_code error;

        size_t bytesReceived;
        socket.receive_from(boost::asio::buffer(*bufferArray), remoteEndpoint, 0, error);
        this->notifier->notifyMessageReceive();
        this->executer->execute(boost::asio::buffer_cast<const char*>(boost::asio::buffer(*bufferArray, bufferArray->size()))); 
        delete bufferArray;
    }

}