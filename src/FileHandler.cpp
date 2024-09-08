#include <iostream>
#include "../include/FileHandler.hpp"

using namespace std;
using namespace File;

FileHandler::FileHandler(string name): name(name)
{


}
FileHandler::~FileHandler()
{
    
}
FileHandler FileHandler::operator=(const FileHandler &f)
{

    return FileHandler("");
}
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
string FileHandler::getContent()
{

}