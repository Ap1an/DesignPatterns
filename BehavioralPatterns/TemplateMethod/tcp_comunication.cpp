#include "tcp_comunication.h"

void Tcp::Start(void){
    this->CreatSocket();
    this->BindSocket();
    this->Listen();
    this->Accept();
    this->Connect();
    this->Comunication();
}