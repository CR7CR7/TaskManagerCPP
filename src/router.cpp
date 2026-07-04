
#include "router.h"

Router::Router(Database& db) : db_(db) {}

void Router::handleRequest(
    const boost::beast::http::request<boost::beast::http::string_body>& req,
    boost::beast::http::response<boost::beast::http::string_body>& res
) {
    
}
