#include <iostream>
#include "../include/App.hpp"

using namespace std;
using namespace Application;

ServerInterface *App::serverInterface = nullptr;

void App::init(int port)
{
    ServerHandler *serverHandler = new ServerHandler(port);

    serverInterface = serverHandler;

    serverInterface->create();
    serverInterface->setConfig();

}
void App::render(const char* httpQuery)
{
    while(true)
    {
        serverInterface->start();

        serverInterface->sendResponse((char *)httpQuery);

        serverInterface->closeAccept();

    }

}
void App::close()
{
    serverInterface->closeSocket();

}