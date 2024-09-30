#include <iostream>
#include "../include/App.hpp"
#include "../include/FileHandler.hpp"

using namespace std;
using namespace Application;
using namespace File;

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

    FileHandler *file = new FileHandler();

    App::init(9998);

    //App::render("HTTP/1.1 200 OK\nContent-Type:text/html\nContent-Length: 256\n\n<h1>Server testing</h1>");

    string content = file->getContent();

    string httpQuery = "HTTP/1.1 200 OK\nContent-Type:text/html\nContent-Length: 256\n\n" + content;

    App::render(httpQuery.c_str());

    App::close();

    return 0;
}