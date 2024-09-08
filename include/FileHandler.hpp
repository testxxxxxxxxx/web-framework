#ifndef FILE_HANDLER

#define FILE_HANDLER 1

#include <iostream>
#include <fstream>

using namespace std;

namespace File
{
    class FileHandlerInterface
    {
        public:

            virtual string getContent() = 0;

    };
    class FileHandler : public FileHandlerInterface
    {
        fstream file;
        string name;

        public:

            FileHandler(string name = "index.html");
            ~FileHandler();

            FileHandler operator=(const FileHandler &f);

            void operator()(int o);

            virtual string getContent() override;

    };

};

#endif