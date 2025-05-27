#include "client.h"

int mian(int argc, char **argv){
    try{
        if (argc < 2){
            std::cout << "Please input the server's ip:" << std::endl;
        }
        Tcp* server = new CLIENT(argv[1], "8888");
        server->Start();
    }catch (std::exception e){
        std::cout << e.what() << std::endl;
    }
    return 0;
}