#ifndef CLIENT_H
#define CLIENT_H

#include "tcp_comunication.h"

class CLIENT: public Tcp{
public:
    CLIENT(std::string ip, std::string prot): ip_(ip), port_(prot){};
    ~CLIENT(){};

private:
    void CreatSocket() override;
    void BindSocket() override{};
    void Listen() override{};
    void Accept() override{};
    void Connect() override;
    void Comunication() override;
    
private:
    int sockfd_;
    struct sockaddr_in server_;
    std::string ip_;
    std::string port_;
};

#endif