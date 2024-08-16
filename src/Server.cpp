#include <iostream>
#include "../include/Server.hpp"
#include <cstring>
#include <unistd.h>

using namespace std;
using namespace Server;

ServerHandler ServerHandler::operator=(const ServerHandler& s)
{

    return ServerHandler(9998, 1);
}
void ServerHandler::operator()(int o)
{
    int a = 5;
    int b = 4;

    auto f = [&a, &b](int *te) -> int
    {
        *te = 5;

        te++;
        
        return *te;
    };

}
int ServerHandler::create()
{
    //creates new socket as fd

    this->fd = socket(AF_INET, SOCK_STREAM, 0);

    return this->fd;
}
void ServerHandler::setConfig()
{ 
    if(setsockopt(this->fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &this->opt, sizeof(this->opt)))
        throw string("Set options error");

    //set server config

    this->address.sin_family = AF_INET;
    this->address.sin_addr.s_addr = INADDR_ANY;
    this->address.sin_port = htons(this->port);

    this->addrlen = sizeof(this->address);

    //set port for server

    if(bind(this->fd, (struct sockaddr *)&this->address, sizeof(this->address)) < 0)
        throw string("Bind set error");

    //start listening server

    if(listen(this->fd, 3) < 0)
        throw string("Listen error");
}
void ServerHandler::sendResponse(char* buffer)
{
    //sending request to client

    send(this->newSocket, buffer, strlen(buffer), 0);

}
char* ServerHandler::read()
{

}
void ServerHandler::start()
{
    //accepting new connections to server

    this->newSocket = accept(this->fd, (struct sockaddr *)&this->address, &addrlen);

    if(this->newSocket < 0)
        throw string("Accept error");

}
void ServerHandler::closeAccept()
{
    //close newSocket

   close(this->newSocket);
}
void ServerHandler::closeSocket()
{
    //close socket

    close(this->fd);

}