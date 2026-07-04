
#include <boost/beast/core.hpp>
#include <boost/beast/http.hpp>
#include <boost/beast/version.hpp>
#include <boost/asio.hpp>
#include <iostream>

#include "router.h"
#include "database.h"

namespace beast = boost::beast;
namespace http = beast::http;
namespace net = boost::asio;

int main() {
    try {
        // initilise base of data
        Database db("tasks.db");

        // Router
        Router router(db);

        // Boost.Asio IO context
        net::io_context ioc;

        // TCP acceptor – listen on port 8080
        net::ip::tcp::acceptor acceptor(ioc, {net::ip::tcp::v4(), 8080});

        std::cout << "Server running on http://localhost:8080\n";

        for (;;) {
            net::ip::tcp::socket socket(ioc);
            acceptor.accept(socket);

            beast::flat_buffer buffer;
            http::request<http::string_body> req;
            http::read(socket, buffer, req);

            http::response<http::string_body> res;
            router.handleRequest(req, res);

            http::write(socket, res);
        }
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << "\n";
    }

    return 0;
}
