#include <iostream>
#include "../include/App.hpp"

using namespace std;
using namespace Application;

int main(int argc, char *argv[])
{
    //Test case:

    /*ServerInterface *serverInterface;
    ServerHandler *serverHandler = new ServerHandler(9998, 1);

    serverInterface = serverHandler;

    serverInterface->create();

    serverHandler->setConfig();

    while(true)
    {

        serverInterface->start();

        serverInterface->sendResponse("HTTP/1.1 200 OK\nContent-Type:text/html\nContent-Length: 256\n\n<h1>Server testing</h1>");

        serverInterface->closeAccept();

    }

    serverInterface->closeSocket();*/

    App::init(9998);

    App::render("HTTP/1.1 200 OK\nContent-Type:text/html\nContent-Length: 256\n\n<h1>Server testing</h1>");

    App::close();

    return 0;
}