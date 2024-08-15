#include <iostream>
#include "../include/Server.hpp"

using namespace std;
using namespace Server;

int main(int argc, char *argv[])
{
    //Test case:

    ServerInterface *serverInterface;
    ServerHandler *serverHandler = new ServerHandler(8080, 1);

    serverInterface = serverHandler;

    serverInterface->create();

    serverInterface->setConfig();

    serverInterface->start();

    serverInterface->sendResponse("HTTP/1.1 200 OK\nContent-Type:text/html\nContent-Length: 256\n\n<h1>Server testing</h1>");

    serverInterface->closeSocket();

    return 0;
}