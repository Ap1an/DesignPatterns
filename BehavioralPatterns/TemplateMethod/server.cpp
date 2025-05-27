#include "server.h"

void SERVER::CreatSocket(){
    sockfd_ = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd_ == -1){
        throw std::runtime_error("Failed to create the socket");
    }
}

void SERVER::BindSocket(){
    struct sockaddr_in server;
    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = inet_addr(ip_.c_str());
    server.sin_port = atoi(port_.c_str());
    //
    if ((bind(sockfd_, (const sockaddr *)&server, sizeof(server))) == -1){
        throw std::runtime_error("Failed to bind the socket");
    }
}

void SERVER::Listen(){
    if ((listen(sockfd_, 20)) == -1){
        throw std::runtime_error("Failed to listen prot");
    } 
}

void SERVER::Accept(){
    socklen_t len = sizeof(client_);
    connect_sockfd_ = accept(sockfd_, (sockaddr *)&client_, &len);
    if (connect_sockfd_ == -1){
        throw std::runtime_error("Failed to connect client");
    }
}

void SERVER::Comunication(){
    std::string data = "nihao";
    int n = write(sockfd_, &data, sizeof(data));
    if (n == -1){
        throw std::runtime_error("Failed to send data");
    }
}