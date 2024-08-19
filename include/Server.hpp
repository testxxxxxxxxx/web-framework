#ifndef SERVER_HPP

#define SERVER_HPP 1

#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>

using namespace std;

namespace Server
{
    class ServerInterface
    {
        public:

            virtual int create() = 0;
            virtual void setConfig() = 0;
            virtual void sendResponse(char* buffer) = 0;
            virtual char* read() = 0;
            virtual void start() = 0;
            virtual void closeAccept() = 0;
            virtual void closeSocket() = 0;

    };
    class ServerHandler : public ServerInterface 
    {
        int fd, port, opt, newSocket;
        struct sockaddr_in address;
        socklen_t addrlen;

        public:

            ServerHandler(int port = 0, int opt = 1) : port(port), opt(opt)
            {

            }
            virtual ~ServerHandler() = default;

            ServerHandler operator=(const ServerHandler& s);

            void operator()(int o);

        public:

            virtual int create() override;
            virtual void setConfig() override;
            virtual void sendResponse(char *buffer) override;
            virtual char* read() override;
            virtual void start() override;
            virtual void closeAccept() override;
            virtual void closeSocket() override;

    };

};

#endif