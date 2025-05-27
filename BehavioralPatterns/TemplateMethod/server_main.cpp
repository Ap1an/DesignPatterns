#include "server.h"

int main(int argc, char **argv){
    try{
        if (argc < 2){
            std::cout << "Please input the server's ip:" << std::endl;
            return 1;
        }
        std::string ip = argv[1];
        Tcp* server = new SERVER(ip, "8888");
        server->Start();
        delete server;
    }catch (const std::exception& e){
        std::cout << e.what() << std::endl;
    }
    return 0;
}