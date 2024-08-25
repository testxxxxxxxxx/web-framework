#ifndef APP_HPP

#define APP_HPP 1

#include <iostream>
#include "Server.hpp"

using namespace std;
using namespace Server;

namespace Application
{
    class App
    {
        static ServerInterface *serverInterface;

        public:

            static void init(int port);
            static void render(char* httpQuery);
            static void close();

    };

};

#endif