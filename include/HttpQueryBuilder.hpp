#ifndef HTTP_QUERY_BUILDER_HPP

#define HTTP_QUERY_BUILDER_HPP 1

#include <iostream>

using namespace std;

namespace HttpQuery 
{
    enum class HttpStatus
    {
        send = 200,
        redirect = 301,
        error = 404

    };

    class HttpQueryInterface
    {
        public:

            virtual string getQuery() = 0;

    };
    class HttpQueryBuilder : public HttpQueryInterface
    {
        int status;
        string filename; 

        public:

            HttpQueryBuilder(int status, string filename);
            virtual ~HttpQueryBuilder() = default;

            HttpQueryBuilder operator=(const HttpQueryBuilder &h);

            void operator()(int o);

            virtual string getQuery() override;

    };

};

#endif