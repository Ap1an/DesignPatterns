#include "client.h"

void CLIENT::CreatSocket(){
    sockfd_ = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd_ == -1){
        throw std::runtime_error("Failed to create the socket");
    }
}

void CLIENT::Connect(){
    if ((connect(sockfd_, (const sockaddr*)&server_, (socklen_t)sizeof(server_))) == -1){
        throw std::runtime_error("Failed to connect server");
    }
}

void CLIENT::Comunication(){
    std::string data;
    int n = read(sockfd_, &data, sizeof(data));
    if (n == -1){
        throw std::runtime_error("Failed to read data");
    }else{
        std::cout << data << std::endl;
    }
}