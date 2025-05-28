#ifndef TCP_COMUNICATION_H
#define TCP_COMUNICATION_H

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#include <iostream>
#include <string>
#include <exception>
#include <cstring>

class Tcp{
public:
    Tcp(){};
    virtual ~Tcp(){};
    void Start();
    
protected:
    virtual void CreatSocket() = 0;
    virtual void BindSocket() = 0;
    virtual void Listen() = 0;
    virtual void Accept() = 0;
    virtual void Connect() = 0; 
    virtual void Comunication() = 0;
};

#endif