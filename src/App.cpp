#include <iostream>
#include "../include/App.hpp"

using namespace std;
using namespace Application;

App App::operator=(const App &a)
{

    return App(9998);
}
void App::operator()(int o)
{
    int a = 5;
    int b = 4;

    auto f=[&a, &b](int *te) -> int
    {
        *te = 5;
        te++;

        return *te;
    };

}
App::App(int port): port(port)
{


}
App::~App()
{
    this->serverInterface->closeSocket();

}
void App::init()
{
    ServerHandler *serverHandler = new ServerHandler(this->port);

    serverInterface = serverHandler;

    serverInterface->create();
    serverInterface->setConfig();

}