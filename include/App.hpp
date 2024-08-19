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
        int port;
        ServerInterface *serverInterface;

        public:

            App(int port);
            ~App();

            App operator=(const App &a);

            void operator()(int o);

            void init();

    };

};

#endif