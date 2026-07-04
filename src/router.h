#pragma once
#include <string>
#include <boost/beast/http.hpp>
#include "database.h"

namespace http = boost::beast::http;

class Router {
public:
    Router(Database& db);
    void handleRequest(
        const boost::beast::http::request<boost::beast::http::string_body>& req,
        boost::beast::http::response<boost::beast::http::string_body>& res
    );
private:
    Database& db_;
};
