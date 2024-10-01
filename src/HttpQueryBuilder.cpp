#include <iostream>
#include "../include/HttpQueryBuilder.hpp"

using namespace std;
using namespace HttpQuery;

HttpQueryBuilder::HttpQueryBuilder(int status, string filename): status(status), filename(filename)
{

}
HttpQueryBuilder HttpQueryBuilder::operator=(const HttpQueryBuilder &h)
{

    return HttpQueryBuilder(200, "index.html");
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

}