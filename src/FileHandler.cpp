#include <iostream>
#include "../include/FileHandler.hpp"

using namespace std;
using namespace File;

FileHandler::FileHandler(string name): name(name)
{
    this->open();
}
/*FileHandler FileHandler::operator=(const FileHandler& f)
{

    return FileHandler("");
}*/
void FileHandler::operator()(int o)
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
void FileHandler::open()
{
    this->file.open(this->name, ios::in);

}
string FileHandler::getContent()
{
    string line = "";
    string content = "";

    while(!this->file.eof())
    {
        this->file >> line;

        content += line;

    }

    return content;
}