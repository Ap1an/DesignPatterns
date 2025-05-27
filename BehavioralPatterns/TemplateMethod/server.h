#ifndef SERVER_H
#define SERVER_H

#include "tcp_comunication.h"

class SERVER: public Tcp{
public:
    SERVER(std::string ip, std::string prot): ip_(ip), port_(prot){};
    ~SERVER(){};
private:
    void CreatSocket() override;
    void BindSocket() override;
    void Listen() override;
    void Accept() override;
    void Connect() override{};
    void Comunication() override;
private:
    int sockfd_;
    int connect_sockfd_;
    struct sockaddr_in client_;
    std::string ip_;
    std::string port_;
};

#endif