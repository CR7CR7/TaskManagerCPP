
#pragma once
#include <boost/asio.hpp>
#include <boost/beast.hpp>
#include "router.h"

namespace net = boost::asio;
namespace beast = boost::beast;
namespace http = beast::http;
using tcp = net::ip::tcp;

class Server {
public:
    Server(const std::string& address, unsigned short port, Router& router);

    void run();

private:
    std::string address_;
    unsigned short port_;
    Router& router_;

    void handleSession(tcp::socket socket);
};
