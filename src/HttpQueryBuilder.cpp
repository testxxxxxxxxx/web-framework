#include <iostream>
#include "../include/HttpQueryBuilder.hpp"

using namespace std;
using namespace HttpQuery;

HttpQueryBuilder::HttpQueryBuilder(int status, string filename, string contentType, int contentLength): status(status), filename(filename), contentType(contentType), contentLength(contentLength)
{

}
HttpQueryBuilder HttpQueryBuilder::operator=(const HttpQueryBuilder &h)
{

    return HttpQueryBuilder(200, "index.html", "text/html", 0);
}
void HttpQueryBuilder::operator()(int o)
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
string HttpQueryBuilder::getQuery()
{
    string strStatus = to_string(this->status);

    if(this->status == 200)
        strStatus += " OK";

    string httpQuery = string("HTTP/1.1") + " " + strStatus + "\n" +" Content-Type:" + this->contentType + "\n" +" Content-Length:" + to_string(this->contentLength) + "\n"; 
}