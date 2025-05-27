cmake_minimum_required(VERSION 3.28)
project(tcp)
set(CMAKE_CXX_STANDARD 17)

add_executable(server 
            server_main.cpp 
            server.cpp 
            tcp_comunication.cpp 
            server.h 
            tcp_comunication.h)