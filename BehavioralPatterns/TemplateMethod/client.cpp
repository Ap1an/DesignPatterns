#include "client.h"

void CLIENT::CreatSocket(){
    sockfd_ = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd_ == -1){
        throw std::runtime_error("Failed to create the socket");
    }
}

void CLIENT::Connect(){
    memset(&server_, 0, sizeof(server_));
    server_.sin_family = AF_INET;
    server_.sin_addr.s_addr = inet_addr(ip_.c_str());
    server_.sin_port = atoi(port_.c_str());

    if ((connect(sockfd_, (const sockaddr*)&server_, (socklen_t)sizeof(server_))) == -1){
        throw std::runtime_error("Failed to connect server");
    }
}

void CLIENT::Comunication(){
    std::string data;
    int n = read(sockfd_, &data, 10);
    if (n == -1){
        throw std::runtime_error("Failed to read data");
    }else{
        std::cout << data << std::endl;
    }
}